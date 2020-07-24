"use strict";
exports.__esModule = true;
var Node_1 = require("./Node");
var LinkedList = /** @class */ (function () {
    function LinkedList() {
        this.head = null;
    }
    LinkedList.prototype.print = function () {
        var ptr = this.head;
        while (ptr !== null) {
            console.log(ptr.data);
            ptr = ptr.next;
        }
    };
    LinkedList.prototype.push_front = function (data) {
        var newNode = new Node_1.Node(data);
        var ptr = this.head;
        if (ptr === null) {
            this.head = newNode;
        }
        else {
            newNode.next = this.head;
            this.head = newNode;
        }
    };
    LinkedList.prototype.find = function (data) {
        var ptr = this.head;
        while (ptr) {
            if (ptr.data === data) {
                return true;
            }
            ptr = ptr.next;
        }
        return false;
    };
    LinkedList.prototype.pop_front = function () {
        if (this.head) {
            this.head = this.head.next;
        }
    };
    LinkedList.prototype.pop_back = function () {
        var ptr = this.head;
        var prev = null;
        if (ptr === null) {
            this.head = null;
        }
        while (ptr) {
            if (ptr.next === null) {
                prev.next = null;
                break;
            }
            prev = ptr;
            ptr = ptr.next;
        }
    };
    LinkedList.prototype.remove = function (data) {
        var ptr = this.head;
        var prev = null;
        while (ptr) {
            if (ptr.data === data) {
                if (prev === null) {
                    this.pop_front();
                }
                else {
                    prev.next = ptr.next;
                }
                return true;
            }
            prev = ptr;
            ptr = ptr.next;
        }
        return false;
    };
    LinkedList.prototype.push_back = function (data) {
        var ptr = this.head;
        var newNode = new Node_1.Node(data);
        if (ptr === null) {
            this.head = newNode;
        }
        while (ptr !== null) {
            if (ptr.next === null) {
                ptr.next = newNode;
                break;
            }
            ptr = ptr.next;
        }
    };
    return LinkedList;
}());
;
exports["default"] = LinkedList;
