// JavaScript Document
var items=document.getElementsByClassName("item");
var points=document.getElementsByClassName("yk");
var index=0;
var time=0;
var clearActive=function(){
	for(var i=0;i<items.length;i++){
		points[i].className="yk";
		items[i].className="item";
		}
	}

var goIndex=function(){
	clearActive();
	points[index].className="yk active";
	items[index].className="item active";
	};
var goNext=function(){
	if(index<2){
	index++;
	}else{
		index=0;
		}
	goIndex();
	}

setInterval(function(){
	goNext();
	},2000)
