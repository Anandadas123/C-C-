var fs = require("fs");
var cla = require('command-line-args');
var optDefs = [
    { name: 'file', type: String }
  ];
opts = cla(optDefs);
//console.log(opts.file);
var obj = JSON.parse(fs.readFileSync(opts.file, 'utf8'));

for(var i=0; i < (obj.features).length; i++){
  var arr = [];
  
  for(var j=0;j<obj.features[i].geometry.coordinates[0].length;j++){
    arr.push(obj.features[i].geometry.coordinates[0][j][2]);
  }
  arr.sort();
  var MIN= arr[0];
  var MAX = arr[arr.length -1];
  //var rgbColor = obj.features[i].properties.MODE_RGB;
  //console.log(rgbColor.split(')')[0]);
  //console.log(rgbColor.split(')')[0]+")");
  //obj.features[i].properties.RGB=rgbColor.split(')')[0]+")";
  obj.features[i].properties.MIN=MIN;
  obj.features[i].properties.MAX=MAX;
  
}
var objResult =fs.writeFileSync(opts.file+'1.geojson', JSON.stringify(obj));


//for(var i=0; i < (obj.features).length; i++){
//  console.log(obj.features[i].geometry.coordinates[0][0]);  
//  console.log(obj.features[i].geometry.coordinates[0][0].length); 
//  if(obj.features[i].geometry.coordinates[0][0]==2)
//    obj.unlink(obj.features[i]); 
//}
//var objResult =fs.writeFileSync(opts.file+'1.geojson', JSON.stringify(obj));
