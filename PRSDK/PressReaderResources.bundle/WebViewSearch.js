// We're using a global variable to store the number of occurrences

var MyApp_SearchResultCount = 0;
var rootElementId = "scroller";

//var colors = ["#C4F95F", "cyan", "orange"];

String.prototype.regexIndexOf = function(regex, startpos) {
    var indexOf = this.substring(startpos || 0).search(regex);
    return (indexOf >= 0) ? (indexOf + (startpos || 0)) : indexOf;
}

/* 
 * The main entry point to start the search.
 */

function MyApp_HighlightAllOccurencesOfString(keyword) {
    MyApp_RemoveAllHighlights();
    if (keyword && keyword.length > 0) {
        //var kArr = keyword.split("");
        //var pattern = kArr.join("[\\u00AD]*");
        //var re = new RegExp(pattern, 'i');    
        //alert(re);
        //var keywords = [re];
        var keywords = [keyword];
        MyApp_HighlightAllOccurencesOfStringForElement(document.getElementById(rootElementId), keywords);        
    }
}


/* 
 * Helper function, recursively searches in elements and their child nodes.
 */
function MyApp_HighlightAllOccurencesOfStringForElement(element,keywords) {
    if (element) {
        if (element.nodeType == 3) {        // Text node
            var k = 0;
            while (true) {
                var textComponent = keywords[k];
                if (!textComponent) break;
                //var value = element.nodeValue.replace(/\u00AD/g, " ");
                var value = element.nodeValue;
                var idx = value.toLowerCase().indexOf(textComponent);
                //alert(textComponent);
                //var idx = value.search(textComponent);
                //alert(idx);
                if (idx < 0) {
					break;
                } 
                var span = document.createElement("span");
                var text = document.createTextNode(value.substr(idx, textComponent.length));
                span.appendChild(text);
                span.setAttribute("class","MyAppHighlight"/* + colors[k % 3]*/);
                span.style.backgroundColor = "yellow";
                
                ////// CUSTOM STYLES FOR HIGHLIGHTS ///////
                //span.style.border = '1px solid';
                //span.style.borderRadius = '0.4em';
                //span.style.paddingLeft = '2px';
                //span.style.paddingRight = '2px';
                //span.style.marginLeft = '-3px';
                //span.style.marginRight = '-3px';
                
                //span.style.backgroundImage = '-webkit-linear-gradient(top, rgba(255, 255, 255, 1) 0%, rgba(196, 249, 95, 1) 10%, rgba(120, 178, 7, 1) 50%, rgba(120, 178, 7, 1) 51%, rgba(196, 249, 95, 1))';
                //span.style.borderColor = '#A0F302';
                ///////////////////////////////////////////
                
                text = document.createTextNode(value.substr(idx+textComponent.length));
                element.deleteData(idx, value.length - idx);
                var next = element.nextSibling;
                //element.parentNode.appendChild(span);
                //element.parentNode.appendChild(text);
                element.parentNode.insertBefore(span, next);
                element.parentNode.insertBefore(text, next);
                element = text;

                MyApp_SearchResultCount++;	// update the counter
            }
        } else if (element.nodeType == 1) { // Element node
            if (element.style.display != "none" && element.nodeName.toLowerCase() != 'select') {
                for (var i=element.childNodes.length-1; i>=0; i--) {
                    MyApp_HighlightAllOccurencesOfStringForElement(element.childNodes[i],keywords);
                }
            }
        }
    }
}

/* 
 * Helper function, recursively removes the highlights in elements and their childs.
 */
 
function MyApp_RemoveAllHighlightsForElement(element) {
    if (element) {
        if (element.nodeType == 1) {
             if (element.className.indexOf("MyAppHighlight") >= 0) {
                var text = element.removeChild(element.firstChild);
                element.parentNode.insertBefore(text,element);
                element.parentNode.removeChild(element);
                return true;
            } else {
                var normalize = false;
                for (var i=element.childNodes.length-1; i>=0; i--) {
                    if (MyApp_RemoveAllHighlightsForElement(element.childNodes[i])) {
                        normalize = true;
                    }
                }
                if (normalize) {
                    element.normalize();
                }
            }
        }
    }
    return false;
}

/* 
 * The main entry point to remove the highlights.
 */
 
function MyApp_RemoveAllHighlights() {
    MyApp_SearchResultCount = 0;
    MyApp_RemoveAllHighlightsForElement(document.getElementById(rootElementId));
}