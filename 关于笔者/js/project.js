
window.onscroll=function () {
        //  console.log(document.documentElement.scrollTop);
        var top=window.pageYOffset||document.documentElement.scrollTop||
            document.body.scrollTop||0; //兼容写法

        var a1=document.getElementById("home");
        if (top>1000){
            a1.style.opacity=1;
        }else{
            a1.style.opacity=0;
        }
    }