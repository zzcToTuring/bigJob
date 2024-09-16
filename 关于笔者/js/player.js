
window.onload=function(){
    var btn=document.getElementsByClassName("music-btn")[0];
    var ply=document.getElementById("music");
    var srt= document.getElementsByClassName("start")[0];
    var stp= document.getElementsByClassName("stop")[0];
	if (ply.paused) {
            //console.log("暂停");
            srt.style.display = "block";
            stp.style.display = "none";
            ply.play();
            btn.style.backgroundPosition = "-179px -194px";
        }
    btn.onclick = function() {
        console.log("单击");
        if (ply.paused) {
          //  console.log("暂停");
            srt.style.display = "block";
            stp.style.display = "none";
            ply.play();
            btn.style.backgroundPosition = "-179px -194px";
        }
        else {
           // console.log("播放");
            srt.style.display = "none";
            stp.style.display = "block";
            ply.pause();
            btn.style.backgroundPosition = "-137px -153px";
        }
    }
}