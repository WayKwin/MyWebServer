
function$(id){  return document.getElementById(id);}


var _x=0;var _y=0;

function MousePosition(evt){ 
     evt=evt || window.event; 
      _x=evt.clientX+document.documentElement.scrollLeft; 
      _y=evt.clientY+document.documentElement.scrollTop; 

     return true;
}


window.document.onmousemove = MousePosition;



function showframe(frameid,dx,dy){

var dd=$(frameid);
var xx=_x+document.body.scrollLeft+dx;
if(xx<1) xx=1;
dd.style.left=xx+"px";
var yy=_y+document.body.scrollTop+dy;
if(yy<1) yy=1;
dd.style.top=yy+"px";
dd.style.display="block";
}

function hideframe(frameid){$(frameid).style.display="none";}



var hzWeek= new Array("日","一","二","三","四","五","六","日");
var nStr1=new Array('','一','二','三','四','五','六','七','八','九','十','十一','十二');
var nStr2=new Array('初','十','廿','卅');
Animals=new Array("鼠","牛","虎","兔","龙","蛇","马","羊","猴","鸡","狗","猪");
var solarTerm=new Array("立春","雨水","惊蛰","春分","清明","谷雨","立夏","小满","芒种","夏至","小暑","大暑","立秋","处暑","白露","秋分","寒露","霜降","立冬","小雪","大雪","冬至","小寒","大寒");
var monthName=new Array("JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC");
var Gan=new Array("甲","乙","丙","丁","戊","己","庚","辛","壬","癸");
var Zhi=new Array("子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥");

function cyclical(num){return(Gan[num%10]+Zhi[num%12]);}
function cweekday(wday){return hzWeek[wday];}
function GetcDay(d){var s;switch(d){case 10:s='初十';break;case 20:s='二十';break;case 30:s='三十';break;default:s=nStr2[Math.floor(d/10)];s+=nStr1[d%10];break;}return(s);}
function GetcMon(m){var run="";if(m<0){run='闰';m*=-1;}if(m==1) return run+'正';else return run+nStr1[m];}

function writeday()
{


$("y").innerHTML=nyear; 
$("m").innerHTML=nmonth; 
$("n").innerHTML=nday; 
$("w").innerHTML=cweekday(nwday); 
$("yy").innerHTML = nyear;
$("mm").innerHTML=nmonth; 
$("nn").innerHTML=nday; 
$("ww").innerHTML=cweekday(nwday); 

if(nextmon){
	if(nextcount==1) cldinit(1);
	else cldinit(0);

	nextmon=false;
}
else{
	nextday();
}

}


function WriteTime()
{

$("hrs").innerHTML=shape(nhrs); 
$("min").innerHTML=shape(nmin); 
$("sec").innerHTML=shape(nsec);
}





function showsel() {
var x = $("monsel");
for (var i = 1; i < 13; i++) {
var y = document.createElement('option');
y.text = i;

x.options.add(y);

}

x = $("yearsel");
for (i = 1900; i < 2050; i++) {
y = document.createElement('option');
y.text = i;
x.options.add(y);

}

}



function giveinfo()
{
alert("将从服务器获取最新时间\n长时间运行后或者修改了本地时钟，则需要刷新时间");
}


function shape(x){
if(x<=9) return "0"+x;
else return x.toString();
}




function gotobaidu()
{

 window.open("http://www.baidu.com/baidu?word="+encodeURI(document.theForm.q.value),"_blank");
 return false;
}

function gotobing()
{
 window.open("http://www.bing.com/search?q="+encodeURI(document.theForm.q.value),"_blank");
 return false;
}


function gotogoogle()
{
 window.open("http://www.google.com/search?q="+encodeURI(document.theForm.q.value),"_blank");
 return false;
}


function gotociba()
{
 window.open("http://www.iciba.com/"+encodeURI(document.theForm.q.value),"_blank");
 return false;
}



