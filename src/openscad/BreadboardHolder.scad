//Messurements

//Breadboard height
bbh = 9.1;

//Thickness of holder
wall = 3;

//Margin of error for screw
marg = 0.2;

//Faces of circles
faces = 100;


// Round corners and main cube
difference(){    
    
    //Make main cube
    difference(){ 
        translate([0, 0, (bbh+wall)/2-(wall/2)]){
            cube(bbh+wall, center=true);
        }
        // Corner cut out (For rounded corner)
        translate([-bbh/2, -bbh/2, bbh/2])
            cube([wall,wall,wall*10], center=true); 
    }
    
    //Cuts out where breadboard should be
    translate([-wall/2,-wall/2, wall]) cube(bbh, center=true);
}

// Circle for rounded corner
translate([-bbh/2+wall/2, -bbh/2+wall/2, bbh])
        cylinder(wall, r=wall, center=true, $fn=faces);

//Surround circles.
difference() {
    hull() {
        
        //Shape used for hulling
        cube([bbh+wall, bbh+wall, wall], center=true);
        
        //Circle 1
        translate([bbh+wall, 0, 0]) 
            cylinder(wall, d=bbh+wall, center=true,$fn=faces);
        
        //Circle 2
        translate([0, bbh+wall, 0]) 
            cylinder(wall, d=bbh+wall, center=true,$fn=faces);
    }

 

    //Cuts out where breadboard should be because otherwise big plate in bottom
    translate([-wall/2,-wall/2,-wall/2]) cube(bbh, center=true);
    
    //Make screw holes
    translate([bbh+wall/2,0,0]) cylinder(20, d=3+marg, center=true, $fn=faces);
    translate([0,bbh+wall/2,0]) cylinder(20, d=3+marg, center=true, $fn=faces);
}
