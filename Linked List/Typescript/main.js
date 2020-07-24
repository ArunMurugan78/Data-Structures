"use strict";
exports.__esModule = true;
var LinkedList_1 = require("./LinkedList");
function main() {
    var list = new LinkedList_1["default"]();
    list.push_back(11);
    list.push_back(1);
    list.push_back(112);
    list.remove(112);
    list.print();
}
main();
