if (typeof(vidteq) == 'undefined') { vidteq = {}; }

vidteq._autoOpener = function () {
  this.clickedTtno = { };
  this.activeTtno = { };
  this.fconvex =0;
  this.tilecacheUrl = "http://10.4.71.121/stage/vs/tilecache.php?LAYERS=BANG_IDOD&";
}

var layers = [
    ['#FFA07A',       3,          '0-3']
    ,['#FA8072',       6,          '3-6']
    ,['#E9967A',       9,          '6-9']
    ,['#F08080',       12,         '9-12']
    ,['#CD5C5C',       15,         '12-15']
    ,['#DC143C',       18,         '15-18']
    ,['#B22222',       21,         '18-21']
    ,['#FF0000',       50,         '21-50']
];
var all_added_layers = [];
layers.forEach(function(layer,i){
  all_added_layers.push('building_layer-'+i);
}); 
map.on('load',function(){
  map.addSource("garudaMall",{
    "type":"geojson",
    "data":"data/geojson/nandiHills.geojson"
  });
  map.addLayer({
    "id":"nandiHills",
    "type":"fill-extrusion",
    "source":"nandiHills",
    "minzoom":10,
    "interactive": true,
    "layout": {
      "visibility": "visible"
    },
    "paint":{
      "fill-extrusion-height":["-",["to-number",["get", "MAX"]],900], 
      //{
      //  "property": "MAX",
      //  "type": "identity"
      //},
      "fill-extrusion-base":{ 
        "property": "MIN",
        "type": "identity"
      },
      "fill-extrusion-color":"green",
      "fill-extrusion-opacity":0.9,
    }
  });
});
map.on('load',function(){
  map.addSource("nandiHills",{
    "type":"geojson",
    "data":"data/geojson/nandiHills.geojson"
  });
  map.addLayer({
    "id":"nandiHills",
    "type":"fill-extrusion",
    "source":"nandiHills",
    "minzoom":10,
    "interactive": true,
    "layout": {
      "visibility": "visible"
    },
    "paint":{
      "fill-extrusion-height":["-",["to-number",["get", "MAX"]],900], 
      //{
      //  "property": "MAX",
      //  "type": "identity"
      //},
      "fill-extrusion-base":{ 
        "property": "MIN",
        "type": "identity"
      },
      "fill-extrusion-color":"green",
      "fill-extrusion-opacity":0.9,
    }
  });
  var geojson = {
    "type": "FeatureCollection",
    "features": []
  };

  map.addSource("screenBound",{
    "type":"geojson",
    "data": geojson
  });
  
  map.addLayer({
    "id": "screenBound",
    "type": "line",
    "source": "screenBound",
    "layout": {
      "visibility": "visible"
    },
    "paint": {
      "line-color": "#BF93E4",
      "line-width": 4
    } ,
    "line-translate-anchor":"map"
  });
                  /* CameraCentroid style(Screen center point) */

  var geojson = {
      "type": "FeatureCollection",
      "features": []
    };
  
  map.addSource("cameraCentroid",{
    "type":"geojson",
    "data": geojson
  });
  map.addLayer({
    "id": "cameraCentroid",
      "type": "circle",
      "source": "cameraCentroid",
      "layout": {
        "visibility": "visible"
      }
      ,"paint": {
        "circle-color": "green"
        ,"circle-radius": 30
      }
  });
});

    
var bulayersJson ={"label":"CITY_BU-extrusion","no":["0","1","2","3","4","5","6","7"],"min":[0,3,6,9,12,15,18,21],"max":[3,6,9,12,15,18,21,50]};
map.on('load',function(){

  layers.forEach(function(layer, i){
    map.addLayer({
      "id": 'building_layer-'+i,
      "type":"fill-extrusion",
      "source": "composite",
      "source-layer": "CITY_BU",
      "paint": {
        'fill-extrusion-color': layer[0],
        //'fill-extrusion-opacity':0.6,
        'fill-extrusion-height':  ["to-number",["get", "max_height"]],
        'fill-extrusion-base': 0
        ,'fill-extrusion-opacity': 0.8
      }
      //"properties": {
      //                "description": "gid"+__gid+"\n"+min_height+"~"+max_height,
      //}
    });
    // Build out legends
    //buildingLegend.createBuildingLegend(layer[0],i);
    var popup = new mapboxgl.Popup({
       closeButton: false,
       closeOnClick: false
    });
    layers.forEach(function(layer, i) {
       var filters = ['all',['<=', ["to-number",["get", "max_height"]], layer[1]]];
       if (i !== 0) filters.push(['>', ["to-number",["get", "max_height"]], layers[i - 1][1]]);
       map.setFilter('building_layer-' + i, filters);
       map.setFilter('building_layerf-' + i, filters);
       map.setFilter('building_layerl-' + i, filters);
       //buildingLegend.updateItem(layer[2],i);
     });
     map.on('mouseenter', all_added_layers[i], function(e) {
         //map.RasterTileSource = true;
         //map.repaint = true;
         //map.verties = true;
         //map.showOverdrawInspector =true;
         // Change the cursor style as a UI indicator.
         map.getCanvas().style.cursor = 'pointer';
         var coordinates = e.features[0].geometry.coordinates[0][0].slice();
         var description = e.features[0].properties;
         var description1 = description.name;
         var description2 = "<h2>Building Name: "+description1+'<br>'+
                            "Gid No: "+e.features[0].properties.gid+'<br>'+
                            "TT no: "+e.features[0].properties.ttno+'<br>'+
                            "Building min_height: "+e.features[0].properties.min_height+'<br>'+
                            "Building Max_height: "+e.features[0].properties.max_height;
         // Ensure that if the map is zoomed out such that multiple
         // copies of the feature are visible, the popup appears
         // over the copy being pointed to.
        // while (Math.abs(e.lngLat.lng - coordinates[0]) > 180) {
        //     coordinates[0] += e.lngLat.lng > coordinates[0] ? 360 : -360;
        // }
     
         // Populate the popup and set its coordinates
         // based on the feature found.
         popup.setLngLat(coordinates)
             .setHTML(description2)
             .addTo(map);
     });
     
     map.on('mouseleave', all_added_layers[i], function() {
         map.getCanvas().style.cursor = '';
         popup.remove();
     });
     
  });
    
});

map.on('load',function() {
  map.addSource("elevated_roads",{
    "type":"geojson",
    "data":"data/geojson/elevated_roads.geojson"
  });
  map.addLayer({
    "id":"elevated_roads",
    "type":"fill-extrusion",
    "source":"elevated_roads",
    "filter":["all",["<","min",900]],
    //"source-layer": "indoor_od",
    "interactive": true,
     "layout": {
       //"visibility": "visible"
     },
     "paint": {
       "fill-extrusion-height": {
         "property": "max",
         "type": "identity"
       },
       "fill-extrusion-base":{ 
         "property": "min",
         "type": "identity"
       },
       "fill-extrusion-color": {
         "base":1,
         "stops":[
            [16,"rgb(234,223,239)"],
            [17,"rgb(234,223,239)"],
            [18,"rgb(234,223,239)"],
            [19,"rgb(190,190,190)"],
            [19.5,"rgb(140,140,140)"],
            [20,"rgb(110,110,110)"],
            [21,"rgb(110,110,110)"],
            [22,"rgb(110,110,110)"]
          ]},//""rgb(110,110,110)",//"rgb(178,201,209)",//{ 
       //  "property": "rgb",
       //  "type": "identity"
       //},
       "fill-extrusion-translate-anchor":"map",
     }
  });
});
       //camera focus wise bu features layers feacture identifiying //

 
var floorData ={};
var count =0;
vidteq._autoOpener.prototype.createScreenBox = function (count) {
  var geojson = {
    "type": "FeatureCollection",
    "features": [{
      "type": "Feature",
      "geometry": {
        "type": "Polygon",
        "properties": {},
        "coordinates": [[
            [map.getBounds()._sw.lng, map.getBounds()._sw.lat],
            [map.getBounds()._sw.lng, map.getBounds()._ne.lat],
            [map.getBounds()._ne.lng, map.getBounds()._ne.lat],
            [map.getBounds()._ne.lng, map.getBounds()._sw.lat],
            [map.getBounds()._sw.lng, map.getBounds()._sw.lat],
        ]]
      }
    }]
  };

  map.on('load', function() {
    map.addLayer({
      "id": "polygonbounds"+count,
      "type": "line",
      "source": {
        "type": "geojson",
        "data": geojson
      },
      "paint": {
        "line-color": "#BF93E4",
        "line-width": 3
      },
      "line-translate-anchor":"map"
    });
  });
}

vidteq._autoOpener.prototype.addSource = function (fSpec,selTtno) {
  if (map.getSource(fSpec.name)) { 
    return;
  } else {
    map.addSource(fSpec.name,{
      "type": "vector",
      "tiles": [this.tilecacheUrl+"ttno="+selTtno+"&z={z}&x={x}&y={y}"],
      "minzoom": 15,
      "maxzoom": 24
    });
  }
}

vidteq._autoOpener.prototype.storeIopFeature = function (f,leader) {
  // IOP means IDOD Present
  if (!('iopStore' in this)) { this.iopStore = {}; }
  console.log("storeIopFeature");
  var ttno = f.properties.ttno;
  var z = f.tile.z;
  var x = f.tile.x;
  var y = f.tile.y;
  var toStore = this.iopStore;
  if (leader) {
    if (!(leader in this.iopStore)) { this.iopStore[leader] = {members:{}}; }
    toStore = this.iopStore[leader].members;
  }
  if (!(ttno in toStore)) { toStore[ttno] = {tile:{}}; }
  var tile = toStore[ttno].tile;
  if (!(z in tile)) { tile[z] = {}; }
  if (!(x in tile[z])) { tile[z][x] = {}; }
  tile[z][x][y] = f.geometry; 
  toStore[ttno].properties = f.properties;
  //return;

  //var features = map.querySourceFeatures('composite',{
  //  'sourceLayer': 'CITY_BU'
  //});
  //var member;
  //  member = leader;
  //  this.iopStore[member]={};
  //
  //for(var k=0;k<extraTtNO.length;k++){
  //  var oneData;
  //  var filtered = features.filter(function (one) {
  //    var flag=0;
  //    var ttno =one.properties.ttno;
  //    if (extraTtNO[k]!=ttno) { flag=1;return; }
  //    oneData=one;
  //  });
  //  var ttno = oneData.properties.ttno;
  //  //this.iopStore[leader][ttno] = {tile:{}};
  //  if (!(ttno in Object.keys(this.iopStore[leader]))) { this.iopStore[leader][ttno] = {tile:{}}; }
  //  //this.iopStore[member][ttno] = {tile:{}};
  //  var z = oneData.tile.z;
  //  var x = oneData.tile.x;
  //  var y = oneData.tile.y;
  //  //if (!(ttno in this.iopStore)) { this.iopStore[member][ttno] = {tile:{}}; }
  //  //var tile ="tile";
  //   tile = this.iopStore[leader][ttno].tile;
  //  if (!(z in tile)) { tile[z] = {}; }
  //  if (!(x in tile[z])) { tile[z][x] = {}; }
  //  var geom = oneData.geometry;
  //  tile[z][x][y] = geom;
  //  this.iopStore[leader][ttno].properties = oneData.properties;
  //}
}

vidteq._autoOpener.prototype.computeIopAreas = function (filt) {
  var filt = filt || this.iopStore;
  var cameraPolyTrz = this.getScreenPoly();
  map.getSource("screenBound").setData(cameraPolyTrz);
  var ret = {};
  console.log(this.iopStore);
  for (var ttno in this.iopStore) {
    if (!(ttno in filt)) { continue; }
    this.iopStore[ttno].zArea = {};
    this.iopStore[ttno].zXArea = {};
    this.computeGroupArea(this.iopStore[ttno],cameraPolyTrz);
    //var tile = this.iopStore[ttno].tile;
    //for (var z in tile) {
    //  var area = 0;
    //  var xArea = 0;
    //  for (var x in tile[z]) {
    //    for (var y in tile[z][x]) {
    //      var ar = this.getXArea(tile[z][x][y],cameraPolyTrz);
    //      tile[z][x][y].area = ar.featArea;
    //      tile[z][x][y].xArea = ar.xArea;
    //      area += ar.featArea;
    //      xArea += ar.xArea;
    //    }
    //  }
    //  this.iopStore[ttno].zArea[z] = area;
    //  this.iopStore[ttno].zXArea[z] = xArea;
    //  this.iopStore[ttno].area = area;
    //  this.iopStore[ttno].xArea = xArea;
    //  this.iopStore[ttno].xRatio = (xArea/area).toFixed(2);
    //  this.iopStore[ttno].sRatio = (xArea/sArea).toFixed(2);
    //}
    ret[ttno] = [
      parseFloat(this.iopStore[ttno].xRatio)
      ,parseFloat(this.iopStore[ttno].sRatio)
      ,parseFloat((this.iopStore[ttno].dC2B).toFixed(4))
      
    ];
  }
  return ret;
}

vidteq._autoOpener.prototype.computeGroupArea = function (rec,cameraPolyTrz) {
  console.log("computeGroupArea");
  var sArea = turf.area(cameraPolyTrz);
  console.log(cameraPolyTrz);
  var cameraCentroidCenter = turf.centroid(cameraPolyTrz);
  console.log("cameraCentroidCenter");
  console.log(cameraCentroidCenter);
  //console.log(cameraCentroid.geometry);
  //map.getSource("cameraCentroid").setData(cameraCentroid.geometry);
  var cvxData;
  if ('members' in rec) {
    cvxData = this.getConvexHull(rec.members);
    console.log("cvxData members");
    console.log(cvxData);
  } else {
    //cvxData = rec.tile;
    cvxData = rec.tile;
    console.log("cvxData one");
    cvxData = rec.tile;
    //var cvxCentroid = turf.centroid(cvxData);
    //console.log("cameraTileCentroid",cvxCentroid);
    //map.getSource("cameraCentroid").setData(cvxCentroid);
  }
  var oneBuArea = [];
  console.log("single building data");
  for (var z in cvxData) {
    var area = 0;
    var xArea = 0;
    if ('geom' in cvxData[z]) {
      console.log(cvxData[z]);
      var ar = this.getXArea(cvxData[z].geom,cameraPolyTrz);
      console.log("multipleBu"); 
      console.log(cvxData[z].geom);
      var buCentroidCenter = turf.centroid(cvxData[z].geom);
      console.log("buCentroidCenter");
      console.log(buCentroidCenter);
      area = ar.featArea;
      xArea = ar.xArea;
    } else {
      for (var x in cvxData[z]) {
        for (var y in cvxData[z][x]) {
          console.log(cvxData[z][x][y]);
          console.log(cvxData[z][x][y]);
          oneBuArea.push(cvxData[z][x][y]);
          var ar = this.getXArea(cvxData[z][x][y],cameraPolyTrz);
          cvxData[z][x][y].area = ar.featArea;
          cvxData[z][x][y].xArea = ar.xArea;
          area += ar.featArea;
          xArea += ar.xArea;
        }
      }
     console.log("oneBuArea"); 
     console.log(oneBuArea);
     console.log(oneBuArea[0]);
      var buCentroidCenter = turf.centroid(oneBuArea[0]);
      console.log("buCentroidCenter");
      console.log(buCentroidCenter);
    }
    console.log(cameraCentroidCenter.geometry.coordinates[0],cameraCentroidCenter.geometry.coordinates[1]);
    var from = turf.point([cameraCentroidCenter.geometry.coordinates[0],cameraCentroidCenter.geometry.coordinates[1]]);
    var to = turf.point([buCentroidCenter.geometry.coordinates[0],buCentroidCenter.geometry.coordinates[1]]);
    console.log(buCentroidCenter.geometry.coordinates[0],buCentroidCenter.geometry.coordinates[1]);
    var options = {units: 'miles'};

    var distance = turf.distance(from, to);
    console.log("distance");
    console.log(distance);
    rec.dC2B=distance;
    rec.zArea[z] = area;
    rec.zXArea[z] = xArea;
    rec.area = area;
    rec.xArea = xArea;
    rec.xRatio = (xArea/area).toFixed(2);
    rec.sRatio = (xArea/sArea).toFixed(2);
  }
}

vidteq._autoOpener.prototype.getConvexHull = function (members) {
  var ret = {};
  for (var ttno in members) {
    var tile = members[ttno].tile;
    for (var z in tile) {
      if (!(z in ret)) { ret[z] = {coords:[]}; }
      for (var x in tile[z]) {
        for (var y in tile[z][x]) {
          var geom = tile[z][x][y];
          console.log("geom ",geom);
          if (geom.type == "MultiPolygon") {
            for (var i in geom.coordinates[0]) {
              for (var j in geom.coordinates[0][i]) {
                ret[z].coords.push(geom.coordinates[0][i][j]);
              }
            }
          } else {
            //ret[z].coords.concat.apply(ret[z].coords,geom.coordinates[0]);
            for (var i in geom.coordinates[0]) {
              ret[z].coords.push(geom.coordinates[0][i]);
            }
          }
        }
      }
    }
  }
  var oneZ = Object.keys(ret)[0];
  for (var z in ret) {
    var geojson = {
      "type": "FeatureCollection",
      "features": [{
        "type": "Feature",
        "geometry": {
          "type": "Polygon",
          "properties": {},
          "coordinates": [ret[z].coords]
        }
      }]
    };
    if (z == oneZ) { this.showConvexHull(geojson); }
    var cvxData = turf.convex(geojson);
    var cvxCentroid = turf.centroid(cvxData);
    console.log(cvxCentroid);
    //map.getSource("cameraCentroid").setData(cvxCentroid);
    console.log('cvxData for z ',z,' is ',cvxData);
    if (z == oneZ) { this.showConvexHull(cvxData.geometry) };
    ret[z].geom = cvxData.geometry;
  } 
  console.log("Convex hull ",ret);
  return ret;
}

vidteq._autoOpener.prototype.showConvexHull = function (geojson) {
  console.log("convexBound geojson");
  console.log(geojson);
  if (map.getStyle().sources.convexBound) { 
    map.getSource("convexBound").setData(geojson);
    return;
  }
  map.addSource("convexBound",{
    "type":"geojson",
    "data":geojson
  });
  map.addLayer({
    "id": "convexBound1",
    "type": "fill",
    "source": "convexBound",
    "layout": {
      "visibility": "visible"
    },
    "paint": {
      "fill-color": "#BF93E4"
      ,"fill-opacity":0.1
    } 
  });
}

vidteq._autoOpener.prototype.getIopFeatures = function () {
  var features = map.querySourceFeatures('composite',{
    'sourceLayer': 'CITY_BU'
  });
  if (!features || !features.length) { 
    console.log("No features");
    return {}; 
  }

  var myFilterH = {
    61413:true
    ,98219:true
    ,28646:true
    ,349:true  // garuda mall
    //,209492:true
    ,28430:true
    ,60804:true  // majestic bus stand
    //,209497:true  // utility building
    // ,60875:true
    ,244477:true
    ,61121:true
    ,60843:true  // railway station
    ,60862:true
    ,480:true
    ,160:true
  };//60843:true}; //60804:true,6013:true,
  var myFilterHNew = {
    61413:[61413,61412,61638,61639,61640,61641]
    ,98219:[98219]
    ,28646:[28646]   //
    ,209500:[209500]       // garuda mall
    ,209492:[209492]
    ,6013:[6013]
    ,28430:[28430]
    ,209497:[209497] // utility building
    ,60875:[60875]
    ,244477:[244477]
    ,61121:[61121]
    ,60843:[
      60828,60830,60834,60835,60836,60837,60838,60839,60840
      ,60841,60842,60843,60844,60845
    ]  // railway station
    ,60862:[60862]
    ,480:[480]
    ,160:[160]
    ,60804:[
      60802,60803,60804,60805,60806,60807,60808,60809,60810
      ,60814,60815,60861,60865,60866,60867,60868
    ] //megistric bus stop
    //,60842:[60842]
  };
  var allMembersH = {};
  for (var leader in myFilterHNew) {
    for (var j in myFilterHNew[leader]) {
      var member = myFilterHNew[leader][j];
      allMembersH[member] = leader;
    }
  }
  console.log("allMembersH ",allMembersH); 

  var uniq = {};
  var that = this;
   
  var filtered = features.filter(function (one) {
    var ttno = one.properties.ttno;
    if (!allMembersH[ttno]) { return false; }
    var leader = allMembersH[ttno];
    if (!(leader in uniq)) { uniq[leader] = {}; }
    uniq[leader][ttno] = one;
    var leaderP = (myFilterHNew[leader].length > 1) ? leader:null;
    that.storeIopFeature(one,leaderP);
    //that.storeIopFeature(one,leader);
    return true;
    //if (!myFilterHNew[ttno]) { return false; }
    //that.storeIopFeature(one,myFilterHNew[ttno]);
    //uniq[ttno] = myFilterHNew[ttno];
    //return uniq;
  });
  //var filtered = features.filter(function (one) {
  //  var ttno = one.properties.ttno;
  //  if (!myFilterH[ttno]) { return false; }
  //  that.storeIopFeature(one);
  //  uniq[ttno] = true;
  //  return true;
  //});
  if (!filtered.length) { return {}; }
  // now check for all member present
  console.log(" uniq ",uniq);
  var ret = {};
  for (var one in uniq) {
    var memberCount = Object.keys(uniq[one]).length;
    if (memberCount == myFilterHNew[one].length) {
      ret[one] = uniq[one];
    }
  }
  console.log(" ret ",ret);
  return ret;
}
  
vidteq._autoOpener.prototype.moveEnd = function () {
  if (!('shownTtno' in this)) {
    var iopTtnos = this.getIopFeatures();
    console.log("iopTtnos");
    console.log(iopTtnos);
    if (!Object.keys(iopTtnos).length) { return; }
    var sel = this.computeIopAreas(iopTtnos);
    console.log("sel json file");
    console.log(JSON.parse(JSON.stringify(sel)));
    if (Object.keys(sel).length > 1) {
      var t = Object.keys(sel).map(function (one) {
        return {ttno:one,p:sel[one]};
      });
      t.sort(function (a,b) {
        return a.p[2]-b.p[2];
      });
      console.log(t);
      sel = {};
      sel[t[0].ttno] = t[0].p;
    }
    console.log(sel);
    var selTtno = Object.keys(sel)[0];
    if (sel[selTtno][1] >= 0.001) { } else { return; }
    this.shownTtno = selTtno;
    this.autoOpen(selTtno);
  } else {
    var iopTtnos = {};
    iopTtnos[this.shownTtno] = true;
    var sel = this.computeIopAreas(iopTtnos);
    console.log(JSON.parse(JSON.stringify(sel)));
    var selTtno = Object.keys(sel)[0];
    if (sel[selTtno][1] == 0) {
      this.changeFloor('-1',floorData);
      delete this.shownTtno;
    }
  }
}

  
vidteq._autoOpener.prototype.useless = function () {
  var cameraBound = [
    map.getBounds()._sw.lng,map.getBounds()._sw.lat
    ,map.getBounds()._ne.lng,map.getBounds()._ne.lat
  ];

  var cameraPolyRect = turf.bboxPolygon(cameraBound);
  var cameraPolyTrz = this.getScreenPoly();
  var camJson = {
    "type": "FeatureCollection",
    "features": [cameraPolyRect,cameraPolyTrz]
  };
  map.getSource("screenBound").setData(camJson);
  var that = this;
  var areas = filtered.map(function (one) {
    var ret = {
      ttno:one.properties.ttno
      ,area:that.getIntersectingArea(one,cameraPolyTrz)
      ,feat:one
    };
    return ret;
  });
  areas.sort(function(a,b) {
    return a.area-b.area;
  });
  console.log("areas",areas);
  // selection criteria
  //  if only one ttno has max area - choose it
  //  if more than one ttno has max area - sort and choose the max
  //  If you are in finer zoom number - we need different strategy
  // finally chosen ttno is compared to already clicked one
  //var selTtno = filtered[0].properties.ttno;
  var selTtno = areas[0].ttno;
  if (areas[0].area >= 0.1) { // 1 % of the screen
  //if (areas.length == 1 && areas[0] >= 1) { // 1 % of the screen
    if (this.clickedTtno[selTtno]) {} else {
      this.clickedTtno[selTtno] = true;
      //this.createScreenBox(count);
      count++;
      //this.addSource(selTtno);
      console.log("Clicked on ",selTtno);
      this.autoOpen(selTtno);
      //clickBu(selTtno);
    }
    return;
  }
  //if ($("#change2D3D").html()=="2D") { // 1 % of the screen
  ////if (areas.length == 1 && areas[0] >= 1) { // 1 % of the screen
  //  if (this.clickedTtno[selTtno]) {} else {
  //    this.clickedTtno[selTtno] = true;
  //    //this.createScreenBox(count);
  //    //count++;
  //    //this.addSource(selTtno);
  //    this.autoOpen(selTtno);
  //    //clickBu(selTtno);
  //  }
  //  return;
  //}
  if (Object.keys(this.clickedTtno).length) {
    //if(map.getZoom()<19) 
    this.changeFloor('-1',floorData);
    if(map.getZoom()<16){ 
      this.changeFloor('-1',floorData,fName);
    }
    this.clickedTtno = {};
  }
   
  return;
};

vidteq._autoOpener.prototype.getXArea = function (geom,cameraPoly) {
  var featArea = 0;
  var xArea = 0;
  if (geom.type == "MultiPolygon") {
    var xPolyArea = 0;
    for (var p in geom.coordinates) {
      var featPoly = turf.polygon(geom.coordinates[p]);
      featArea =+ turf.area(featPoly);
      var xPoly = turf.intersect(cameraPoly,featPoly);
      if (!xPoly) { continue; }
      xPolyArea += turf.area(xPoly);
    }
    xArea += xPolyArea;
  } else if (geom.type == "Polygon") {
    var featPoly = turf.polygon(geom.coordinates);
    featArea =+ turf.area(featPoly);
    var xPoly = turf.intersect(cameraPoly,featPoly);
    if (xPoly) {
      var xPolyArea = turf.area(xPoly);
      xArea += xPolyArea;
    }
  }
  return {
    featArea:featArea
    ,xArea:xArea
  };
}

vidteq._autoOpener.prototype.getIntersectingArea = function getIntersectingArea(one,cameraPoly) {
  var featArea = 0;
  var xArea = 0;
  var cameraArea = turf.area(cameraPoly);
  console.log("cameraPoly ",cameraPoly);
  console.log("cameraArea ",cameraArea);
  console.log("zoom ",map.getZoom());
  var geom = one.geometry;
  if (geom.type == "MultiPolygon") {
    var xPolyArea = 0;
    for (var p in geom.coordinates) {
      var featPoly = turf.polygon(geom.coordinates[p]);
      featArea =+ turf.area(featPoly);
      console.log("featArea",featArea);
      var xPoly = turf.intersect(cameraPoly,featPoly);
      console.log("xPoly",xPoly);
      if (!xPoly) { continue; }
      xPolyArea += turf.area(xPoly);
    }
    if (xPolyArea < featArea) { return 0; }
    xArea += xPolyArea;
  } else if (geom.type == "Polygon") {
    var featPoly = turf.polygon(geom.coordinates);
    featArea =+ turf.area(featPoly);
    console.log("featArea ",featArea);
    var xPoly = turf.intersect(cameraPoly,featPoly);
    console.log("xPoly ",xPoly);
    if (!xPoly) { return 0; }
    var xPolyArea = turf.area(xPoly);
    console.log("xPolyArea ",xPolyArea);
    if (xPolyArea < featArea) { return 0; }
    xArea += xPolyArea;
  }
  console.log("featArea ",featArea);
  console.log("xArea ",xArea);
  return parseFloat((100*featArea/cameraArea).toFixed(2));
}

vidteq._autoOpener.prototype.addLayers = function (name,floorSelArray) {
  var modeStyles = {
    '2D':[{
      "suffix":"f",
      "type":"fill",
      "source":name,
      "interactive": true,
      "minzoom": 16,
      "layout": {
        "visibility": "none"
      },
      "paint": {
        "fill-color": { 
          "property": "rgb",
          "type": "identity"
        },
        "fill-opacity":0.5
      }
    },{
      "suffix":"_poi",
      "source": name,
      "type": "symbol",
      "interactive": true,
      "layout": {
         "visibility": "none",
         "symbol-placement":"point",
         "symbol-avoid-edges": true,
         //"symbol-sort-key":1000,
         //"symbol-z-order":"auto",
         "icon-allow-overlap": false,
         "icon-ignore-placement": true,
         "icon-padding":0,
         "icon-anchor":"center",
         //"icon-optional": false,
         "icon-size":0.5,
         "icon-image": "{icon}",
        "text-field": "{name}",
        "text-font": ["Open Sans Regular"],
        "text-size":15,
        "text-pitch-alignment": "map",
        "text-allow-overlap": true,
        //"text-ignore-placement": true,
        "text-max-angle": 30,
        "text-offset": [
          0,
          3
        ]
      },
      "paint": {
        "text-color": "#000000",
      }
     //},{
     // "suffix":"_label",
     // "type": "symbol",
     // "source": name,
     // "interactive": true,
     // "layout": {
     //   "visibility": "none",
     //   "text-field": "{name}",
     //   "symbol-placement": "point",
     //    "symbol-avoid-edges": true,
     //    "icon-allow-overlap": false,
     //    "icon-ignore-placement": false,
     //   "icon-optional": false,
     //   "text-font": ["Open Sans Regular"],
     //   "text-size":15,
     //   "text-pitch-alignment": "map",
     //   "text-allow-overlap": true,
     //   "text-max-angle": 30,
     //   "text-offset": [
     //     0,
     //     3
     //   ]
     // },
     // "paint": {
     //   "text-color": "#000000",
     // }
     }]
    //},{
    //  "suffix":"l",
    //  "type":"line",
    //  "source":name,
    //  "interactive": true,
    //  "minzoom":16,
    //  "layout": {
    //    "visibility": "none"
    //  },
    //  "paint": {
    //    "line-color": { 
    //      "property": "rgb",
    //      "type": "identity"
    //    },
    //    "line-width":2,
    //    "line-opacity":0.2
    //  }
    //}]
    ,'3D':[{
      "type":"fill-extrusion",
      "source":name,
      "interactive": true,
      //"filter":["all",["<","min",0],["<","max",0]],
      "layout": {
        "visibility": "none"
      },
      "paint": {
        "fill-extrusion-height": {
          "property": "max",
          "type": "identity"
        },
  
        "fill-extrusion-base":{ 
          "property": "min",
          "type": "identity"
        },
        "fill-extrusion-color": { 
          "property": "rgb",
          "type": "identity"
        },
        "fill-extrusion-translate-anchor":"map",
      }
    }]
  };
  var allLayers = {};
  console.log("floorSelArray ",floorSelArray);
  for (var i in floorSelArray) {
    if (!floorSelArray[i].type) { continue; }
    var type = floorSelArray[i].type;
    if (!(type in allLayers)) { allLayers[type] = {}; }
    var l = floorSelArray[i].layers;
    for (var mode in l) {
      if (!(mode in allLayers[type])) { allLayers[type][mode] = []; }
      for (var j in l[mode]) {
        var oneL = l[mode][j];
        for (var k in modeStyles[mode]) {
          var oneS = modeStyles[mode][k];
          var id = oneL+(('suffix' in oneS)?oneS.suffix:'');
          if(oneS.suffix=="_poi"){
            oneL=oneL+"_poi";
          }
          allLayers[type][mode].push(id);
          var oneLayer = $.extend(true,{
            id:id
            ,"source-layer": oneL
          },oneS);
          delete oneLayer.suffix;
          map.addLayer(oneLayer);
        }
      }
    }
  }
  return allLayers;
}

vidteq._autoOpener.prototype.filterBu = function (ttno,param) {
  var tt = ["!in","ttno"];
  if ('ttArr' in param) {
    tt = tt.concat(Object.values(param.ttArr));
  } else {
    tt = tt.concat([ttno]);
  }
  for(var i=0;i<all_added_layers.length;i++){
    for(var l =0;l<all_added_layers.length;l++) {
      console.log("inside the clickBu foorloop");
      for(var i=0;i<bulayersJson.no.length;i++) {
        if (i ==0){ 
          var filters = ['all',tt,["<=","max_height",bulayersJson.max[i]]];
        } else{ 
          var filters = ['all',tt,[">","max_height",bulayersJson.max[i-1]],["<=","max_height",bulayersJson.max[i]]];
        }
        map.setFilter('building_layer-' + i, filters);
      }
    } 
  }
}

vidteq._autoOpener.prototype.closeFloorSelector = function () {
  //map.dragRotate._pitchWithRotate = true;
  var ttno = $('#floorSelector').data('ttno');
  for(var i=0;i<bulayersJson.no.length;i++) {
    var filters = ['all',["!=","ttno",ttno],["<=","max_height",bulayersJson.max[i]]];
    if (i ==0){ 
      var filters = ['all',["<=","max_height",bulayersJson.max[i]]];
    }else{ 
      var filters = ['all',[">","max_height",bulayersJson.max[i-1]],["<=","max_height",bulayersJson.max[i]]];
    }
    map.setFilter('building_layer-' + i, filters);
  }
  //floorSelector.style.visibility ='hidden';
  $("#change2D3D").hide();
  $('#floorSelector').hide();
}

vidteq._autoOpener.prototype.gotoDefaultFloor = function (ttno,fArray,fName) {
  $('.floor').removeClass('clicked');  
  $('.floor-9').addClass('clicked');
  $('#floorSelector').show();
  this.changeFloor('9',fArray,fName);
};
vidteq._autoOpener.prototype.changeFloor = function (clickedFloor,floorSelArray,fName) {
  if (clickedFloor == -1) {
    this.closeFloorSelector();
    //map.removeSource(fName);
  } 
  var mode = $('#floorSelector').data('mode');
  var layerHash = {};
  var layerHashAuto = {};
  var layerIndoorHash = {};
  // first switch off layers
  var selLayer;
  for (var i in floorSelArray) {
    var md = $("#change2D3D").html();
    //if (clickedFloor!=0){
    //  var l = Object.values(floocloseFloorSelectorrSelArray[i].layers)[0];
    //} else {
    //  var l = Object.values(floorSelArray[i].layers);
    //}
    if(md == "3D") {
      var l = floorSelArray[i].layers["3D"];
      if (floorSelArray[i].floorIdx == clickedFloor) {
        selLayer = l;
      }
      for (var j in l) {
        layerHash[l[j]] = 'none';
      }
      for (var i in selLayer) {
         layerHash[selLayer[i]] = 'visible';
      }
    }
    if(md == "2D") {
      var l = floorSelArray[i].layers["2D"];
      if (floorSelArray[i].floorIdx == clickedFloor) {
        selLayer = l;
      }
      for (var j in l) {
        layerHash[l[j]] = 'none';
        layerHash[l[j]+"f"] = 'none';
      }
      for (var i in selLayer) {
         layerHash[selLayer[i]+"f"] = 'visible';
         layerHash[selLayer[i]+"_poi"] = 'visible';
         layerHash[selLayer[i]+"_poi_label"] = 'visible';
      }
    }
  }
  for (var i in layerHash) {
    console.log(layerHash[i]);
    map.setLayoutProperty(i, 'visibility',layerHash[i]);
  }
  if(md == "2D"){
    var popup1 = new mapboxgl.Popup({
       closeButton: false,
       closeOnClick: false
  });
  map.on('mouseenter', selLayer[0]+"_poi", function(e) {
  console.log(e);
  var geom = e.features[0].geometry;
  map.getCanvas().style.cursor = 'pointer';
  var coordinates = geom.coordinates;
  var description =  e.features[0].properties;
  var description1 = description.name;
  var description2 = "<h2 style=position:relative;left:40%;>Poi Name: "+description1+'<br>'+
                     "Gid No: "+e.features[0].properties.gid+'<br>'+
                     "Image Id: "+e.features[0].properties.imageid+'<br>'+
                     "Image Name: "+e.features[0].properties.image_name+"</h2>";
  console.log(e.features[0].properties.image_name);
  var imageUrl ="http://10.4.71.145/DMT/D3V/images/Mall_Image/"+e.features[0].properties.image_name+".jpg";
  popup1.setLngLat(coordinates)
      .setHTML(//description2+'<br>'+
      '<img src='+imageUrl+' style="width: 200px; height: 200px;left:0%;right:80%;" >'
      )
          .addTo(map);
  });
  map.on('mouseleave', selLayer[0]+"_poi", function() {
      map.getCanvas().style.cursor = '';
      popup1.remove();
      //map.setLayoutProperty("poiColor","visibility","none"); 
  });
  var flagPoi=0;
  map.on('click', selLayer[0]+"_poi", function(e) {
  var geom = e.features[0].geometry;
  var coordinates = geom.coordinates;

  var html="";
  $('#imageSliderOuterContainer').show();
  if((map.getStyle().sources.CirclePoi)) {
    var length = $('#imageSliderContainer > div').length;
    for(var i=4;i<length;i++){
        var id = $($('#imageSliderContainer > div')[4]).attr('id');
        $("div#"+id).remove();
    }
  }
  var fName = e.features[0].layer.source;
    var poiFeature = map.querySourceFeatures(fName,{  
                        'sourceLayer':selLayer[0]+"_poi"          
                     });
   var imageUrl ="http://10.4.71.145/DMT/D3V/images/Mall_Image/"+e.features[0].properties.image_name+".jpg";
    for(var i=0; i< poiFeature.length;i++){
      var url = "http://10.4.71.145/DMT/D3V/images/Mall_Image/"+poiFeature[i].properties.image_name+".jpg";
      var geom = poiFeature[i].geometry;
      var coordinates1 = [geom.coordinates[0],geom.coordinates[1]];
      var html = "";
       if(poiFeature[i].properties.image_name != "undefined"){
        var localId = "imageInnerDom_"+poiFeature[i].properties.image_name;
       html += "<div id='"+localId+"' data-imagename='"+poiFeature[i].properties.image_name+"'imagename='"+poiFeature[i].properties.name+"'coordinates='"+coordinates1+"'>";
       html += "<img src='"+url+"' style='width:100%;'/>";
       html += "</div>";
       $('[id^="imageInnerDom_"]').each(function () { $(this).hide(); });
       if($('#'+localId).length) {
         $("#"+localId).remove();
       }
       $('#imageSliderContainer').append(html);
      }

    }
    var html1 = "";
    var localId = "imageInnerDom_"+$(this).attr('data-imagename');
    html1 += "<div id='"+localId+"' data-imagename='"+$(this).attr('data-imagename')+"'>";
    html1 += "<img src='"+imageUrl+"' style='width:100%;'/>";
    html1 += "</div>";
    $('[id^="imageInnerDom_"]').each(function () { $(this).hide(); });
    if($('#'+localId).length) {
      $("#"+localId).remove();
    }
    $('#imageSliderContainer').append(html1);
    var cord= {
      "type":"FeatureCollection",
      "features": [{
        "type": "Feature",
        "geometry": {
          "type": "Point",
          "coordinates": coordinates
        }
      }]
    };
    if(flagPoi==0) {
      if(!(map.getStyle().sources.CirclePoi)) {
        map.addSource("CirclePoi",{type:'geojson',data:cord});
      } else {
        map.getSource("CirclePoi").setData(cord);
      }
      map.addLayer({
        "id": "CirclePoi",
        "type": "circle",
        "source": "CirclePoi",
        "layout": {
          "visibility": "visible"
        }
        ,"paint": {
          "circle-color": "#BF93E4"
          ,"circle-radius": 30
          ,"circle-opacity":0.4
        }
      });
      flagPoi=1;
    }else {
      map.getSource("CirclePoi").setData(cord);
    }
    
    $('#imageSliderOuterContainer').show();
    $('#imageSliderContainer').show();
    $('#imageSlidername').show();
    $('#imageSliderLeft').show();
    $('#imageSliderRight').show();
    $('#imageSliderClose').show();
    $('#imageName').html(e.features[0].properties.name);
      
    interact('#imageSliderOuterContainer')
    .draggable({
      // enable inertial throwing
      inertia: true,
      // keep the element within the area of it's parent
      modifiers: [
        interact.modifiers.restrict({
          restriction: "parent",
          endOnly: true,
          elementRect: { top: 0, left: 0, bottom: 1, right: 1 }
        }),
      ],
      // enable autoScroll
      autoScroll: true,

      // call this function on every dragmove event
      onmove: dragMoveListener,
      // call this function on every dragend event
      onend: function (event) {
        var textEl = event.target.querySelector('p');

        textEl && (textEl.textContent =
          'moved a distance of '
          + (Math.sqrt(Math.pow(event.pageX - event.x0, 2) +
                       Math.pow(event.pageY - event.y0, 2) | 0))
              .toFixed(2) + 'px');
      }

    })
    .resizable({
      // resize from all edges and corners
      edges: { left: true, right: true, bottom: true, top: true },

      modifiers: [
        // keep the edges inside the parent
        interact.modifiers.restrictEdges({
          outer: 'parent',
          endOnly: true,
        }),

        // minimum size
        interact.modifiers.restrictSize({
          min: { width: 100, height: 50 },
        }),
      ],

      inertia: true
    })
    .on('resizemove', function (event) {
      var target = event.target,
          x = (parseFloat(target.getAttribute('data-x')) || 0),
          y = (parseFloat(target.getAttribute('data-y')) || 0);

      // update the element's style
      target.style.width  = event.rect.width + 'px';
      target.style.height = event.rect.height + 'px';

      // translate when resizing from top or left edges
      x += event.deltaRect.left;
      y += event.deltaRect.top;

      target.style.webkitTransform = target.style.transform =
          'translate(' + x + 'px,' + y + 'px)';

      target.setAttribute('data-x', x);
      target.setAttribute('data-y', y);
      //target.textContent = Math.round(event.rect.width) + '\u00D7' + Math.round(event.rect.height);
    });
    function dragMoveListener (event) {
    var target = event.target,
        // keep the dragged position in the data-x/data-y attributes
        x = (parseFloat(target.getAttribute('data-x')) || 0) + event.dx,
        y = (parseFloat(target.getAttribute('data-y')) || 0) + event.dy;

    // translate the element
    target.style.webkitTransform =
    target.style.transform =
      'translate(' + x + 'px, ' + y + 'px)';

    // update the posiion attributes
    target.setAttribute('data-x', x);
    target.setAttribute('data-y', y);
  }

  // this is used later in the resizing and gesture demos
  window.dragMoveListener = dragMoveListener;

   });
   $('#imageSliderLeft').click(function (e) {
     var im = undefined;
     var h = undefined;
     if($('[id^="imageInnerDom_"]').length > 1) {
       //$('#imageSliderContainer div').each(function (i) {}
       $('[id^="imageInnerDom_"]').each(function (i) {
       var arr=[];
       var cord;
         if(i == 0 ) {
           im = $(this).attr('data-imagename');
           var coordinates = $(this).attr('coordinates');
           console.log(im);
           if(im!='undefined'){
             arr.push(coordinates.split(","));
             var index=coordinates.indexOf(",");
             arr.push(coordinates.substring(index+1,coordinates.length));
             console.log(arr);
             arr[0]=parseFloat(arr[0]);
             arr[1]=parseFloat(arr[1]);
             
             cord= {
               "type":"FeatureCollection",
               "features": [{
                 "type": "Feature",
                 "geometry": {
                   "type": "Point",
                   "coordinates": arr
                 }
               }]
             };
            map.getSource("CirclePoi").setData(cord);
          }
         }
         //if(i == $('#imageSliderContainer div').length - 1) {}
         if(i == $('[id^="imageInnerDom_"]').length - 1) {
           h = $(this).detach();
           h.insertBefore($('#imageInnerDom_'+im));
           $('[id^="imageInnerDom_"]').each(function () { $(this).hide(); });
           $('[id^="imageInnerDom_"]').each(function (j) { 
             if(j == $('[id^="imageInnerDom_"]').length - 1) {
               //console.log(cord);
               $(this).show(); 
               $('#imageName').html($(this).attr('imagename')); 
             }
           });
         }
         return;
       });
     }
   });
   $('#imageSliderClose').click(function () {
     $('#imageSliderContainer').hide();
     $('#imageSliderOuterContainer').hide();
     var cord= {
         "type":"FeatureCollection",
         "features": [{
           "type": "Feature",
           "geometry": {
             "type": "Point",
             "coordinates": []
           }
         }]
       };
       map.getSource("CirclePoi").setData(cord);
   });
   
   //$("#imageSliderRight").mouseover(function(){
   //  $("#imageSliderRight").css("background-color", "yellow");
   //});
   //$("#imageSliderLeft").mouseover(function(){
   //  $("#imageSliderRight").css("background-color", "yellow");
   //});
   $('#imageSliderRight').click(function () {
     var im = undefined;
     var h = undefined;
     if($('[id^="imageInnerDom_"]').length > 1) {
       //$('#imageSliderContainer div').each(function (i) {}
       $('[id^="imageInnerDom_"]').each(function (i) {
       var arr=[];
       var cord;
         if(i == 0) {
           h = $(this);
           im = $(this).attr('data-imagename');
           var coordinates = $(this).attr('coordinates');
           console.log(coordinates);
           console.log(im != 'undefined' && coordinates != 'undefined');
           
           if(im != 'undefined' && coordinates != 'undefined'){
             arr.push(coordinates.split(","));
             var index=coordinates.indexOf(",");
             arr.push(coordinates.substring(index+1,coordinates.length));
             console.log(arr);
             arr[0]=parseFloat(arr[0]);
             arr[1]=parseFloat(arr[1]);
             
             cord= {
               "type":"FeatureCollection",
               "features": [{
                 "type": "Feature",
                 "geometry": {
                   "type": "Point",
                   "coordinates": arr
                 }
               }]
             };
            map.getSource("CirclePoi").setData(cord);
          }
         }
         //if(i == $('#imageSliderContainer div').length - 1) {}
         if(i == $('[id^="imageInnerDom_"]').length - 1) {
           im = $(this).attr('data-imagename');
           h.detach().insertAfter($('#imageInnerDom_'+im));
           $('[id^="imageInnerDom_"]').each(function () { $(this).hide(); });
           $('[id^="imageInnerDom_"]').each(function (j) { 
             if(j == $('[id^="imageInnerDom_"]').length - 1) {
               $(this).show(); 
               $('#imageName').html($(this).attr('imagename')); 
             }
           });
         }
       });
     }
   });
  }
  //if(map.getZoom()== 15 || map.getZoom()<16){ 
  //  for (var i in layerHashAuto) {
  //    map.setLayoutProperty(i, 'visibility',layerHashAuto[i]);
  //  }
  //}
}

vidteq._autoOpener.prototype.change2D3D = function (button,ttno,fArray) {
  if($(button).html() == "3D") {
    $('#floorSelector').data('mode','2D');
    $(".floor.floor-0").hide();
    this.gotoDefaultFloor();
    $(button).html("2D");
    for(var j=0;j<all_added_layers.length;j++){
      map.setPaintProperty(all_added_layers[j],"fill-extrusion-height",0);
    }
    var rotate=map._canvas.baseURI; //location.hash
    var link="";
    for(var i in rotate){
      if(rotate[i]=='#')
        break;
      else
        link+=rotate[i];   
     }
    var rotate1=location.hash;
    var rotate2 =rotate1.split("/");
    var rotate3 ="";
    if((rotate2.length>=1 && rotate2.length<=3) || rotate2.length==4 || rotate2.length==5){     
      for(var i in rotate2){ 
        if(i>=0 && i<=2){
          rotate3+=rotate2[i]+"/";
          link2d= link+rotate3;
        }
        if(i==3) {
          $(button).data("pitch",rotate2[i]);
          rotate3+=rotate2[i]+"/";
        }
        if(i==4) {
          $(button).data("roll",rotate2[i]);
          //rotate3+=rotate2[i]+"/";
        }
      }
    }
    link = link+rotate3;
    $(button).data("link",link2d);
    location.href = link;
    //map.dragRotate.disable();
    //map.pitchWithRotate = false;
    map.dragRotate._pitchWithRotate = false;
    $('#floorSelector').data('inited',false);
    //$('#floorSelector').html('');
      //map.removeSource("gopalanMall_mvt");
      //map.getLayoutProperty("indoor_od", 'visibility');
      this.addSource(fArray,ttno);
      this.autoOpen(ttno);
    //vidteq.autoOpener.moveEnd(); 
  } else if($(button).html() == "2D") {
     $('#floorSelector').data('mode','3D');
     $(".floor.floor-0").show();
     this.gotoDefaultFloor();
     for(var j=0;j<all_added_layers.length;j++){
        map.setPaintProperty(all_added_layers[j],"fill-extrusion-height",["to-number",["get", "max_height"]]);
     }
     $(button).html("3D");
     map.dragRotate._pitchWithRotate = true;
     var link = $(button).data("link");
     var pitch = $(button).data("pitch");
     var roll = $(button).data("roll");
     if(pitch=="undefined"){
       link=link;
     } else {
       link+=pitch+"/";
     }
     if(roll=="undefined"){
       link=link;
     } else {
       link+=roll;
     }
     location.href = link;
      this.addSource(fArray,ttno);
      this.autoOpen(ttno);
  }
}

vidteq._autoOpener.prototype.openFloorSelector = function (ttno,fArray,fName) {
  var oldTtno = $('#floorSelector').data('ttno');
  if (oldTtno && oldTtno == ttno) {
    $("#change2D3D").show();
    $('#floorSelector').show();
    return;
  }
  if (oldTtno) {
    $('#floorSelector').data('inited',false);
    $('#floorSelector').html('');
  }
  if ($('#floorSelector').data('inited')) { } else {
    for (var i in fArray) {
      $('#floorSelector').append($("<div class='"+fArray[i].class+"' data-floor-idx='"+fArray[i].floorIdx+"'>"+fArray[i].floorLabel+"</div>"));
    }
    $('#floorSelector').data('inited',true);
  }
  //floorSelector.style.visibility ='visible';
  $("#change2D3D").show();
  $('#floorSelector').show();
  $('#floorSelector').data('ttno',ttno);
  $('#floorSelector').data('mode','3D');
}

vidteq._autoOpener.prototype.showIndoor = function (ttno,fArray,fName) {
  this.openFloorSelector(ttno,fArray,fName);
  var that = this;
  $('.floor').unbind('click'); 
  $('.floor').click(function(evt) {
    $('.floor').removeClass('clicked');    
    $(this).addClass('clicked');
    var floorIdx = $(this).attr('data-floor-idx');
    that.changeFloor(floorIdx,fArray,fName);
  });
  this.gotoDefaultFloor(ttno,fArray,fName);
  var that = this;
  $('#change2D3D').unbind('click'); 
  $("#change2D3D").click(function(event) {
    that.change2D3D(this,ttno,fArray);
  });
}

vidteq._autoOpener.prototype.autoOpen = function (ttno) {
  //if (this.activeTtno[ttno]) { 
  //  console.log("already active "+ttno);
  //  return;
  //}
  var that = this;
  var floorSpecUrl = this.tilecacheUrl+"floorSpec=1&ttno="+ttno;
  $.ajax({
    type: 'GET',
    url: floorSpecUrl,
    //url: 'data/'+ttno+'.json',
    dataType: "json",
    success: function (fSpec) {
      console.log("FloorSpec is "); 
      console.log(fSpec); 
      if (!fSpec.floorSelArray) { 
        console.log("Error no floor array json file");
        return;
      }
      if (Object.keys(that.activeTtno).length) { 
        for (var i in that.activeTtno) {
          var old = that.activeTtno[i];
          // if earlier ttno was active and their corresponding layer and source,
          // You need to detect and delete them before adding new
          // need to remove all the layers before deleting the source
          //map.removeSource(old.name);
        }
        that.activeTtno = {};
        // for now I am assuming only one ttno can be active at any point of time
      }
      that.activeTtno[ttno] = fSpec;
      that.addSource(fSpec,ttno);
      var allLayers = that.addLayers(fSpec.name,fSpec.floorSelArray);
      console.log("allLayers3D");
      console.log(allLayers);
      var md = $("#change2D3D").html();
      if(md == "3D") {
        //for(var j =0;j<fSpec.floorSelArray.length;j++){
        //  delete fSpec.floorSelArray[j].layers["2D"];
        //}
        fSpec.floorSelArray.push(
          {class:'floor floor-0 clicked',floorIdx:'0',floorLabel:'ALL',layers:{"3D":allLayers.id["3D"]}}
        );
      }
      if(md == "2D") {
        //for(var j =0;j<fSpec.floorSelArray.length;j++){
        //  delete fSpec.floorSelArray[j].layers["3D"];
        //}
        fSpec.floorSelArray.push(
          {class:'floor floor-0 clicked',floorIdx:'0',floorLabel:'ALL',layers:{"2D":allLayers.id["2D"]}}
        );
      }
      fSpec.floorSelArray.push(
        {class:'floor floor--1 ',floorIdx:'-1',floorLabel:' X',layers:{}}
      );
      floorData = fSpec.floorSelArray;
      that.clickBu(parseInt(ttno),fSpec);
    },
    error: function (res) {
      console.log("Error no floor array json file");
    }
  });

}
//map.on('moveend',function(){
//  if(map.getZoom()== 16 || map.getZoom()<16){
//      console.log("inside moveend for 16 zoom"); 
//      this.changeFloor('-1',floorData);
//  }
//});

vidteq._autoOpener.prototype.clickBu = function (ttno,param) {
  var that =this;
  that.filterBu(ttno,param);
  var fArray = param.floorSelArray;
  var fName = param.name;
  that.showIndoor(ttno,fArray,fName);
}

vidteq._autoOpener.prototype.getScreenPoly = function () {
  //if (!bounds instanceof mapboxgl.LngLatBounds) {
  //  throw new TypeError('Expecting bounds to be mapboxgl.LngLatBounds, got ' + bounds);
  //}
  var canvas = map.getCanvas(),
  w = canvas.width,
  h = canvas.height,
  cUL = map.unproject ([0,0]).toArray(),
  cUR = map.unproject ([w,0]).toArray(),
  cLR = map.unproject ([w,h]).toArray(),
  cLL = map.unproject ([0,h]).toArray();
  var coordinates = [cUL,cUR,cLR,cLL,cUL];
  return turf.polygon([coordinates]);
}

vidteq.autoOpener = new vidteq._autoOpener(map);

map.on('moveend', function () {
  console.log("move end");
  var md = $("#change2D3D").html();
  vidteq.autoOpener.moveEnd(); 
  if(map.getZoom()== 16 || map.getZoom()<16){
      vidteq.autoOpener.changeFloor('-1',floorData);
  }
});

var popup1 = new mapboxgl.Popup({
   closeButton: false,
   closeOnClick: false
});
map.on('mouseenter', 'CITY_RP-line1', function(e) {
           console.log("inside mouseenter");
           map.getCanvas().style.cursor = 'pointer';
           
           console.log(e);

           var coordinates = e.features[0].geometry.coordinates[0][0].slice();
           //var description = e.features[0].properties;
           //var description1 = description.name;
           //var description2 = "<h2>Building Name: "+description1+'<br>'+
           //                   "Gid No: "+e.features[0].properties.gid+'<br>'+
           //                   "TT no: "+e.features[0].properties.ttno+'<br>'+
           //                   "Building min_height: "+e.features[0].properties.min_height+'<br>'+
           //                   "Building Max_height: "+e.features[0].properties.max_height;
           popup1.setLngLat(coordinates)
               .setHTML(description2)
               .addTo(map);
          });
     
           map.on('mouseleave', 'CITY_RP-line1', function() {
           map.getCanvas().style.cursor = '';
           popup1.remove();
         });

//var countpoi =0;
//var flagpoi = 0;
 //map.on('mouseenter', "indoor_id_g_poi", function(e) {
 //    console.log(e);
 //    var geom = e.features[0].geometry;
 //    map.getCanvas().style.cursor = 'pointer';
 //    var coordinates = geom.coordinates;
 //    var description =  e.features[0].properties;
 //    var description1 = description.name;
 //    var description2 = "<h2 style=position:relative;left:40%;>Poi Name: "+description1+'<br>'+
 //                       "Gid No: "+e.features[0].properties.gid+'<br>'+
 //                       "Image Id: "+e.features[0].properties.imageid+'<br>'+
 //                       "Image Name: "+e.features[0].properties.image_name+"</h2>";
 //    console.log(e.features[0].properties.image_name);
 //    var imageUrl ="http://10.4.71.145/DMT/D3V/images/Mall_Image/"+e.features[0].properties.image_name+".jpg";
 //    //var poiGeojson = {
 //    //  "type": "FeatureCollection",
 //    //  "features": [{
 //    //    "type": "Feature",
 //    //    "geometry": {
 //    //      "type": "Point",
 //    //      "properties": {},
 //    //      "coordinates": [coordinates[0],coordinates[1]]
 //    //    }
 //    //  }]
 //    //};
 //    //if(flagpoi ==0){
 //    //  map.addSource("poiColor",{
 //    //    "type":"geojson",
 //    //    "data":poiGeojson 
 //    //  });
 //    //  flagpoi=1;
 //    //}else{
 //    //  map.getSource("poiColor").setData(poiGeojson);
 //    //}

 //   // map.addLayer({
 //   //   "id": "poiColor",
 //   //   "type": "circle",
 //   //   "source": "poiColor",
 //   //   "layout": {
 //   //     "visibility": "visible"
 //   //   },
 //   //   "paint": {
 //   //     "circle-color": "blue",
 //   //     "circle-radius":10
 //   //   }
 //   // });
 //    //map.getSource("poiColor").setData(poiGeojson);
 //    
 //    //'<img src='+imageUrl+ '"width: 20%; height: 20%;"'+' >'
 //    popup1.setLngLat(coordinates)
 //        .setHTML(//description2+'<br>'+
 //        '<img src='+imageUrl+' style="width: 200px; height: 200px;left:0%;right:80%;" >'
 //        )
 //        .addTo(map);
 //});
 //map.on('mouseleave', "indoor_id_g_poi", function() {
 //    map.getCanvas().style.cursor = '';
 //    popup1.remove();
 //    //map.setLayoutProperty("poiColor","visibility","none"); 
 //});
 //map.on('click', "indoor_id_g_poi", function(e) {
 //  console.log(e);
 //  var geom = e.features[0].geometry;
 //  map.getCanvas().style.cursor = 'pointer';
 //  var coordinates = geom.coordinates;
 //  var imageUrl ="http://10.4.71.145/DMT/D3V/images/Mall_Image/"+e.features[0].properties.imagename+".jpg";
 // // var row =  "<div class="row" >";
 // // var column = "<div class="column">";
 // // var imageStyle ="<img src="imageUrl" style="width:100%" onclick="openModal();currentSlide(1)" class="hover-shadow cursor">";
 // // var div = "</div>";
 // // var myModel = "<div id="myModal" class="modal">";
 // // var closeModel ="<span class="close cursor" onclick="closeModal()">&times;</span>";
 // // var modeContent = "<div class="modal-content">";
 //  //var slideIndex = 1;
 //  //showSlides(slideIndex);
////   $("body").append(
////            //row,column,imageStyle,div,div,myModel,closeModel,modeContent
////    '  <img src="1001116.jpg" style="width:100%" onclick="openModal();currentSlide(1)" class="hover-shadow cursor">  '
//// );
////  $(".caption-container").append('  <img src="1001116.jpg" style="width:100%" onclick="openModal();currentSlide(1)" class="hover-shadow cursor">  '
////);
 //  popup1.setLngLat(coordinates)
 //      .setHTML(//description2+'<br>'+
 //      '<img src='+imageUrl+' >'
 //      )
 //      .addTo(map);
 //  //$(.caption-container).innerHTML('<img src='+imageUrl+' >'); 
 //});

//https://www.w3schools.com/howto/tryit.asp?filename=tryhow_css_js_lightbox

//function openModal() {
//  console.log("inside openModel");
//  document.getElementById('myModal').style.display = "block";
//}
//
//function closeModal() {
//  document.getElementById('myModal').style.display = "none";
//}
//
//var slideIndex = 1;
//showSlides(slideIndex);
//
//function plusSlides(n) {
//  showSlides(slideIndex += n);
//}
//
//function currentSlide(n) {
//  showSlides(slideIndex = n);
//}
//
//function showSlides(n) {
//  var i;
//  var slides = document.getElementsByClassName("mySlides");
//  console.log(slides);
//  var dots = document.getElementsByClassName("demo");
//  var captionText = document.getElementById("caption");
//  if (n > slides.length) {slideIndex = 1}
//  if (n < 1) {slideIndex = slides.length}
//  for (i = 0; i < slides.length; i++) {
//      slides[i].style.display = "none";
//  }
//  for (i = 0; i < dots.length; i++) {
//      dots[i].className = dots[i].className.replace(" active", "");
//  }
//  //slides[slideIndex-1].style.display = "block";
//  console.log("slideIndex");
//  console.log(dots[slideIndex]);
//  dots[slideIndex].className += " active";
//  captionText.innerHTML = dots[slideIndex1].alt;
//}
     //extra job for camera projection
