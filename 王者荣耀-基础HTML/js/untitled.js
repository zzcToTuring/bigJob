var items=document.getElementsByClassName("item");
var goPrebtn=document.getElementById("goPre");
var goNextbtn=document.getElementById("goNext");
var points=document.getElementsByClassName("yk");
var myaudio1=document.createElement("audio");
var index=0;
var time=0;
var clearActive=function(){
	for(var i=0;i<items.length;i++){
		points[i].className="yk";
		items[i].className="item";
		}
	}
var autoPlay=function(){
	if(index==0){
	myaudio1.src="./Audio/韩信剪.mp3"	
	myaudio1.play();}
	if(index==1){
	myaudio1.src="./Audio/孙悟空剪.mp3"	
	myaudio1.play();}
	if(index==2){
	myaudio1.src="./Audio/花木兰剪.mp3"	
	myaudio1.play();}
	if(index==3){
	myaudio1.src="./Audio/李白剪.mp3"	
	myaudio1.play();}
	if(index==4){
	myaudio1.src="./Audio/孙尚香剪.mp3"	
	myaudio1.play();}
	if(index==5){
	myaudio1.src="./Audio/貂蝉剪.mp3"	
	myaudio1.play();}
	if(index==6){
	myaudio1.src="./Audio/吕布剪.mp3"	
	myaudio1.play();}
}
var goIndex=function(){
	clearActive();
	points[index].className="yk active";
	items[index].className="item active";
	autoPlay();
	};
	
var goNext=function(){
	if(index<6){
	index++;
	}else{
		index=0;
		}
	goIndex();
	}
var goPre=function(){
	if(index==0){
	index=6;
	}else{
		index--;
		}
	goIndex();
	}	
 goNextbtn.addEventListener("click",function(){
	goNext();
	time=0;
	})
goPrebtn.addEventListener("click",function(){
	goPre();
	time=0;
	})
for(var i=0;i<points.length;i++){
	points[i].addEventListener("click",function(){
		var pointsIndex=this.getAttribute("data-index");
		index=pointsIndex;
		goIndex();
		time=0;
		})
	}	

setInterval(function(){
	time++;
	if(time==20){
	goNext();
	time=0;
	}
	},250)
	
		