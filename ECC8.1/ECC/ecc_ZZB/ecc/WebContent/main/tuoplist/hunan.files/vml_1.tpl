<html xmlns:v="urn:schemas-microsoft-com:vml" 
 xmlns="http://www.w3.org/TR/REC-html40">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5"/>
<link rel="stylesheet" type="text/css" href="visio.css"/>
<title></title>
<style type="text/css">
	 v\:* { behavior: url(#default#VML); }
</style>

<script src="vml_1.js" type="text/jscript" language="jscript"></script>

<script type="text/jscript" language="jscript">

	var pageID = 0;
	var viewMgr = null;

	if (parent.g_FirstPageToLoad != null && parent.g_FirstPageToLoad.length > 0)
	{
		if (parent.g_FileList[parent.g_CurPageIndex].PageID != pageID)
		{
			location.replace(parent.g_FileList[parent.g_CurPageIndex].PriImage);
		}

		parent.g_FirstPageToLoad = null;
	}

	function getPNZ()
	{
		var rawHTML = VMLDiv.innerHTML;
		var strReturn = ""
		
		strReturn = rawHTML.slice( rawHTML.indexOf( '<v:group' ), rawHTML.indexOf( "</v:shape>" ) );
		strReturn += "</v:shape></v:group>\n";
				
		return strReturn;
	}
	
	function load()
	{
		viewMgr = new parent.CViewMgr("ConvertedImage", "arrowDiv");

		viewMgr.put_Location = ViewMgrSetVMLLocation;


		viewMgr.visBBoxLeft = -2.197889;
		viewMgr.visBBoxRight = 10.441000;
		viewMgr.visBBoxBottom = 1.696741;
		viewMgr.visBBoxTop = 9.960630;

		viewMgr.Zoom = VMLZoomChange;
		viewMgr.setView= VMLSetView;

		viewMgr.SupportsDetails = true;
		viewMgr.SupportsSearch = true;

		parent.viewMgr = viewMgr;

		fit();
	}

	function unload()
	{
		viewMgr = null;
		parent.viewMgr = null;
	}

	function fit()
	{
		if(parent.frmToolbar)
		{
			if (parent.g_WidgetsLoaded)
			{
				var zoom100 = parent.frmToolbar.document.all('a100');
				if (zoom100)
				{
					parent.viewMgr.PostZoomProcessing = PostZoomProcessing;
					zoom100.click();
				}
				else
				{
					parent.viewMgr.PostZoomProcessing = PostZoomProcessing;
					viewMgr.Zoom(100);
				}
			}
			else
			{
				window.setTimeout("fit()", 500);
			}
		}	
		else
		{
			parent.viewMgr.PostZoomProcessing = PostZoomProcessing;
			viewMgr.Zoom(100);
		}
	}

	function PostZoomProcessing (newZoomLevel)
	{
		parent.viewMgr.PostZoomProcessing = null;
		var pageIndex = parent.PageIndexFromID (pageID);
		parent.viewMgr.getPNZ = getPNZ;
		parent.CurPageUpdate (pageIndex);
	}


	
	var isUpLevel = parent.isUpLevel;
	var OnShapeClick = parent.OnShapeClick;
	var OnShapeKey = parent.OnShapeKey;
	var UpdateTooltip = parent.UpdateTooltip;
	var clickMenu = parent.clickMenu;
	var toggleMenuDiv = parent.toggleMenuDiv;
	var toggleMenuLink = parent.toggleMenuLink;
	var GoToPage = parent.GoToPage;

	window.onload = load;
	window.onunload = unload;
	document.onclick = clickMenu;




</script>

</head>

<body style="MARGIN:10px" onresize="VMLOnResize();" onscroll="VMLOnScroll();">

<div id="arrowdiv" style="position:absolute;top:0;left:0;visibility:hidden;z-index:5">
<img id="arrowgif" alt="显示所选形状的位置" src="arrow.gif"/>
</div>

<div id="menu1" onclick="clickMenu()" class="hlMenu">
</div>




<div id="VMLDiv" >


<v:group  id="ConvertedImage" style="width:6.117647in;height:4.000000in;position:absolute;visibility=hidden;" coordSize="3059,2000" coordOrigin="-1000,-1000" >

<v:shapetype 
  id="VISSHAPE"
  target="_parent"
  coordsize="3059,2000"
  coordorigin="-1000,-1000"
  stroked="f"
  strokecolor="red"
  filled="t"
>
<v:fill opacity="0.0"/>
</v:shapetype>


<v:shape style="top:-1000.0;left:-1000.0;width:3058.8;height:2000.0;position:absolute" coordSize="3059,2000" coordOrigin="-1000,-1000" >
<v:imagedata src="vml_1.emz"/>
</v:shape>

<v:shape type="#VISSHAPE"  href="#" fillcolor="SV_Group:长沙+color" tabindex="1" title="长沙" origTitle="长沙"  style="top:-1000;left:-1000;width:3059;height:2000;position:absolute" path=" m 1134,-276 l 1134,-222 l 1214,-222 l 1214,-276 l 1134,-276xe" onmouseover="UpdateTooltip(this,0,2)" onclick="OnShapeClick(0,2)" onfocus="UpdateTooltip(this,0,2);" onkeyup="OnShapeKey(0,2)"/> 

<v:shape type="#VISSHAPE"  href="#" fillcolor="SV_Group:岳阳+color" tabindex="1" title="岳阳" origTitle="岳阳"  style="top:-1000;left:-1000;width:3059;height:2000;position:absolute" path=" m 1110,-590 l 1110,-535 l 1190,-535 l 1190,-590 l 1110,-590xe" onmouseover="UpdateTooltip(this,0,3)" onclick="OnShapeClick(0,3)" onfocus="UpdateTooltip(this,0,3);" onkeyup="OnShapeKey(0,3)"/> 

<v:shape type="#VISSHAPE"  href="#" fillcolor="SV_Group:株洲+color" tabindex="1" title="株洲" origTitle="株洲"  style="top:-1000;left:-1000;width:3059;height:2000;position:absolute" path=" m 1172,94 l 1172,148 l 1252,148 l 1252,94 l 1172,94xe" onmouseover="UpdateTooltip(this,0,12)" onclick="OnShapeClick(0,12)" onfocus="UpdateTooltip(this,0,12);" onkeyup="OnShapeKey(0,12)"/> 

<v:shape type="#VISSHAPE"  href="#" fillcolor="SV_Group:湘潭+color" tabindex="1" title="湘潭" origTitle="湘潭"  style="top:-1000;left:-1000;width:3059;height:2000;position:absolute" path=" m 887,-144 l 887,-89 l 967,-89 l 967,-144 l 887,-144xe" onmouseover="UpdateTooltip(this,0,14)" onclick="OnShapeClick(0,14)" onfocus="UpdateTooltip(this,0,14);" onkeyup="OnShapeKey(0,14)"/> 

</v:group>



</div>



</body>
</html>

<script>
function reloadrefresh()
{
parent.location.reload();window.setTimeout("reloadrefresh()", 180000);
}
window.setTimeout("reloadrefresh()", 180000)
var date = new Date(); 
var msg = "The Last Refresh Time : " + date.toLocaleDateString() + date.toLocaleTimeString();   
function scroll(seed) 
{ 
var out = " ";    
var c = 1; 
if (seed > 100) { 
seed--; 
var cmd="scroll(" + seed + ")"; 
timerTwo=window.setTimeout(cmd,100); 
} 
else if (seed <= 100 && seed > 0) { 
for (c=0 ; c < seed ; c++) { 
out+=" "; 
} 
out+=msg; 
seed--; 
var cmd="scroll(" + seed + ")"; 
window.status=out;
timerTwo=window.setTimeout(cmd,100);
} else if (seed <= 0) { 
if (-seed < msg.length) { 
out+=msg.substring(-seed,msg.length); 
seed--; 
var cmd="scroll(" + seed + ")"; 
window.status=out;
timerTwo=window.setTimeout(cmd,100); 
} 
else { 
window.status=" ";
timerTwo=window.setTimeout("scroll(100)",7); 
} 
} 
} 
timerONE=window.setTimeout('scroll(100)',50); 
</script>
*#siteview7endflag#*
