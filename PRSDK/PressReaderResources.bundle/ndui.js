
$.nd = {};


(function($) {

    $.nd.ui = {};
    $.nd.ui.columns = (function() {
        // Example:
        /*
        var def = { elmId: "cont", maxColumns: 0, columnWidth: 0, makeColumnsEqual: true, columnClass:"col" };
        onload = function() {
        $.nd.ui.columns.updateColumns(def);
        };
        onresize = function() {
        $.nd.ui.columns.updateColumns(def);
        };
        */

        function reorderColumnsFast(cols) {
            // reorder columns comparing child count(fast)
            var activeCols = checkColumns(cols, true);
            var childCounts = 0;
            // calculate childs
            for (var i = 0; i < activeCols; i++) {
                childCounts += cols[i].childNodes.length;
            }
            var itemsPerColumn = Math.ceil(childCounts / activeCols);
            for (var i = 0; i < activeCols - 1; i++) {
                var col = cols[i], nextcol = cols[i + 1]; ;
                var currentChilds = col.childNodes.length;
                while (currentChilds < itemsPerColumn) {
                    if (!nextcol.firstChild) {
                        // next col doesn't have childs (ie the childs been already moved), 
                        // so try to find other columns with childs
                        for (var j = i + 2; j < activeCols; j++) {
                            nextcol = cols[j]
                            if (!nextcol || nextcol.firstChild)
                                break;
                        }
                    }
                    if (!nextcol || !nextcol.firstChild)
                        break;
                    col.appendChild(nextcol.firstChild);
                    currentChilds++;
                }
                while (currentChilds > itemsPerColumn) {
                    nextcol.insertBefore(col.lastChild, nextcol.firstChild);
                    currentChilds--;
                }
            }
        };
        function reorderColumns(cols) {
            // reorder columns comparing columns height (slow)
            var cols_count = cols.length;
            var isChanged = true;
            while (isChanged) {
                isChanged = false;
                var prevCol = cols[0];
                var prevColHeight = prevCol.offsetHeight;
                for (var i = 1; i < cols_count; i++) {
                    var col = cols[i];
                    if (!col.isActiveCol)
                        break;
                    var height = col.offsetHeight;
                    while (height > prevColHeight && col.firstChild) {
                        prevCol.appendChild(col.firstChild);
                        isChanged = true;
                        height = col.offsetHeight;
                        prevColHeight = prevCol.offsetHeight;
                    }
                    if (isChanged)
                        break;
                    prevCol = col;
                    prevColHeight = height;
                }
            }
        };
        function reorderColumnsToBeEqual(cols) {
            var cols_count = cols.length;
            var isChanged = true;
            while (isChanged) {
                isChanged = false;
                var prevCol = cols[0];
                var prevColHeight = prevCol.offsetHeight;
                for (var i = 1; i < cols_count; i++) {
                    var col = cols[i];
                    if (!col.isActiveCol)
                        break;
                    var height = col.offsetHeight;
                    if (height < prevColHeight) {
                        // if current column height less then prev column height
                        // try to add node from next column
                        // to make columns the same height (except last one)
                        var nextCol = cols[i + 1];
                        if (nextCol && nextCol.isActiveCol && nextCol.firstChild) {
                            var movedNode = col.appendChild(nextCol.firstChild);
                            if (col.offsetHeight > prevColHeight) {
                                // cancel changes
                                nextCol.insertBefore(movedNode, nextCol.firstChild);
                            } else {
                                if (!nextCol.firstChild)
                                    shiftColumns(cols, i + 1);
                                isChanged = true;
                                break;
                            }
                        }
                    }
                    prevCol = col;
                    prevColHeight = height;
                }
            }
        };
        function shiftColumns(cols, toIndex) {
            var col = cols[toIndex];
            var nextCol = cols[toIndex + 1];
            if (nextCol) {
                if (nextCol.firstChild) {
                    moveAllChildren(nextCol, col);
                    shiftColumns(cols, toIndex + 1);
                }
            }
            if (!col.firstChild) {
                col.isActiveCol = false;
                col.style.display = "none";
            }
        }
        function reorderColumnsReverse(cols, lastColumnIdx) {
            var isChanged = true;
            while (isChanged) {
                isChanged = false;
                var prevCol = cols[lastColumnIdx];
                var prevColHeight = prevCol.offsetHeight;
                for (var i = lastColumnIdx - 1; i >= 0; i--) {
                    var col = cols[i];
                    var height = col.offsetHeight;
                    if (height > prevColHeight) {
                        prevCol.insertBefore(col.lastChild, prevCol.firstChild);
                        isChanged = true;
                        break;
                    }
                    prevCol = col;
                    prevColHeight = height;
                }
            }
        };
        function checkColumns(cols, doNotCheckForChidren) {
            var active = 0;
            for (var i = cols.length - 1; i >= 0; i--) {
                var col = cols[i];
                if (col.isActiveCol) {
                    if (!doNotCheckForChidren && !col.firstChild) {
                        col.isActiveCol = false;
                        col.style.display = "none";
                    }
                    else active++;
                }
            }
            return active;
        }
        function moveAllChildren(fromNode, toNode) {
            var child = fromNode.firstChild;
            while (child) {
                var c = child;
                child = child.nextSibling;
                toNode.appendChild(c);
            }
        };
        function insertAfter(parentNode, node, insertAfterNode) {
            if (!insertAfterNode || !insertAfterNode.nextSibling)
                parentNode.appendChild(node);
            else
                parentNode.insertBefore(node, insertAfterNode.nextSibling);
        };
        function createCol(parentNode, insertAfterNode, createResetElm, width, className) {
            // [col.style.float = "left"] - doesn't work in IE and Firefox, so use innerHTML to set float
            var col = document.createElement("div");
            col.innerHTML = "<div style='float:left;'></div>";
            col = col.firstChild;
            col.isCol = true;
            col.isActiveCol = false;
            col.style.display = "none";
            if (width)
                col.style.width = width;
            if (className)
                col.className = className;
            insertAfter(parentNode, col, insertAfterNode);

            if (createResetElm) {
                // reset floating elm
                var clear = document.createElement("div");
                clear.style.clear = "both";
                clear.isClearCol = true;
                insertAfter(parentNode, clear, insertAfterNode);
            }
            return col;
        };
        function fisSizeVal(val, defaultVal) {
            if (val) {
                if (typeof val === "number")
                    return val + "px";
                if (typeof val === "string" && val.length > 0) {
                    if (val != "auto") {
                        var c = val.charAt(val.length - 1);
                        if (c >= '0' && c <= '9')
                            return val + "px"; // is last char is number
                    }
                    return val;
                }
            }
            return defaultVal;
        };


        var _api = {
            enableColumns: function(contId) {
                $("#" + contId + " [enbaleColumn='true']").enableColumns();
            },
            updateColumns: function(cfg) {
                var cont = cfg.elm || document.getElementById(cfg.elmId);
                if (!cont || cont._isUpdatingColumns) return;
                try {
                    // updating columns could call onresize events and it could be recursive call
                    cont._isUpdatingColumns = true;

                    var maxColumns = cfg.maxColumns;
                    if (!maxColumns && maxColumns !== 0) {
                        var _val = cont.getAttribute("maxColumns");
                        if (_val && _val != "auto")
                            maxColumns = parseInt(_val);
                    }
                    if (!maxColumns || maxColumns == "auto")
                        maxColumns = 1000;
                    if (maxColumns > 30)
                        maxColumns = 30;

                    var columnWidth = fisSizeVal(cfg.columnWidth || cont.getAttribute("columnWidth"), null);
                    var makeColumnsEqual = cfg.makeColumnsEqual || cont.getAttribute("makeColumnsEqual") == "true";
                    var columnClass = cfg.columnClass || cont.getAttribute("columnClass");
                    var ignoreText = cfg.columnIgnoreText || cont.getAttribute("columnIgnoreText") == "true";
                    var fastMode = (cfg.columnConstructionMode || cont.getAttribute("columnConstructionMode")) == "fast";

                    // it would be nice to implemet columnMinWidth
                    //var columnMinWidth = fisSizeVal(cfg.columnMinWidth || cont.getAttribute("columnMinWidth"), 0);
                    //if (columnWidth && columnWidth != "auto") {
                    //  columnMinWidth = 0;
                    //}

                    // find columns
                    var cols = [], activeCols = 0;
                    if (cont._isColInited) {
                        // find columns
                        var child = cont.firstChild;
                        while (child) {
                            if (child.isCol) {
                                cols.push(child);
                                if (child.isActiveCol)
                                    activeCols++;
                            }
                            child = child.nextSibling;
                        }
                    }
                    if (!cols.length) {
                        cont._isColInited = true;

                        // create first col
                        var col = createCol(cont, null, true, columnWidth, columnClass);
                        col.style.display = "block";
                        col.isActiveCol = true;
                        cols.push(col);
                        activeCols++;

                        // move all childs to first col
                        var childsCount = 0;
                        var child = cont.firstChild;
                        while (child) {
                            var c = child;
                            child = c.nextSibling;
                            if (!c.isCol && !c.isClearCol) {
                                if (ignoreText && c.nodeType == 3)
                                    continue;
                                col.appendChild(c);
                                childsCount++;
                            }
                        }
                        if (childsCount == 0)
                            return;

                        var maxWidth = $.css(col, "width");
                        // adjust maxcol
                        maxColumns = Math.min(maxColumns, Math.floor($(window).width() / maxWidth));

                        // create additional columns
                        var top1 = col.offsetTop;
                        while (activeCols < maxColumns) {
                            col = createCol(cont, cols[activeCols - 1], false, columnWidth, columnClass);
                            cols.push(col);
                            col.style.display = "block";
                            var top2 = col.offsetTop;
                            if ($.css(col, "width") < maxWidth) {
                                // if the size is not set offsetTop will be always equal to prev's column top
                                col._prevColWidth = col.style.width || "auto";
                                col.style.width = maxWidth + "px";
                                top2 = col.offsetTop;
                            }
                            if (top2 > top1) {
                                // we cannot add more columns
                                col.style.display = "none";
                                break;
                            }
                            col.isActiveCol = true;
                            activeCols++;
                        }
                        for (var i = cols.length - 1; i >= 0; i--) {
                            var col = cols[i];
                            if (col._prevColWidth) {
                                col.style.width = col._prevColWidth;
                                col._prevColWidth = null;
                            }
                        }
                        reorderColumnsFast(cols);
                        activeCols = checkColumns(cols);
                    }
                    // 1. check if active columns fit to available space
                    // to do that we need compare offsetTop of each column to offsetTo of first column
                    // if column has offsetTop bigger then first column's one then the col was moved to down because of floating ie it was not enough space to place col
                    var top1 = cols[0].offsetTop;
                    var isChanged = false;
                    for (var i = activeCols - 1; i > 0; i--) {
                        var col = cols[i];
                        if (col.offsetTop > top1) {
                            // col is not fit to current space, so move content to previos columns
                            moveAllChildren(col, cols[i - 1]);
                            col.style.display = "none";
                            col.isActiveCol = false;
                            isChanged = true;
                            continue;
                        }
                        break;
                    }
                    if (isChanged) {
                        if (fastMode) {
                            reorderColumnsFast(cols);
                        } else {
                            reorderColumns(cols);
                            if (makeColumnsEqual) {
                                checkColumns(cols);
                                reorderColumnsToBeEqual(cols);
                            }
                        }
                        return;
                    }

                    if (makeColumnsEqual && !fastMode) {
                        reorderColumns(cols);
                        checkColumns(cols);
                        reorderColumnsToBeEqual(cols);
                    }


                    if (activeCols == maxColumns || activeCols == 0)
                        return;

                    // 2. try to add more columns
                    isChanged = false;
                    while (activeCols < maxColumns) {
                        // get first not active column
                        var col = cols[activeCols];
                        if (!col) {
                            // create one more col and insert after previous column but before clear elm
                            col = createCol(cont, cols[activeCols - 1], false, columnWidth, columnClass);
                            cols.push(col);
                        }
                        col.style.display = "block";
                        var top2 = col.offsetTop;
                        if ($.css(col, "width") == 0) {
                            // if the size is not set offsetTop will be always equal to prev's column top
                            var prevval = col.style.width;
                            col.style.width = $.css(cols[activeCols - 1], "width") + "px";
                            top2 = col.offsetTop;
                            col.style.width = prevval || "auto";
                        }
                        if (top2 > top1) {
                            // we cannot add more columns
                            col.style.display = "none";
                            break;
                        }
                        col.isActiveCol = true;
                        if (fastMode) {
                            reorderColumnsFast(cols);
                        } else {
                            reorderColumnsReverse(cols, activeCols);
                            reorderColumns(cols);
                        }
                        // check again, the column's width could increase and column
                        if (col.offsetTop > top1) {
                            moveAllChildren(col, cols[activeCols - 1]);
                            col.isActiveCol = false;
                            col.style.display = "none";

                            if (fastMode) {
                                reorderColumnsFast(cols);
                            } else {
                                reorderColumns(cols);
                                if (makeColumnsEqual) {
                                    checkColumns(cols);
                                    reorderColumnsToBeEqual(cols);
                                }
                            }
                            break;
                        }

                        activeCols++;
                    }
                    if (makeColumnsEqual && !fastMode) {
                        checkColumns(cols);
                        reorderColumnsToBeEqual(cols);
                    }
                }
                finally {
                    cont._isUpdatingColumns = false;
                }
            }
        };
        function each_enableColumns(idx, elm) {
            var cfg = {
                elm: elm
            };
            _api.updateColumns(cfg);
            cfg.elm = null;
        };
        $.fn.enableColumns = function() {
            return this.each(each_enableColumns);
        };
        return _api;
    })();

})(jQuery);
