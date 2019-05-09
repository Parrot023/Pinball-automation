//Body messurements
depth = 10;
height = 7;

//Cutout messurements
cutout_length = 11;
cutout_height = 5;

//Divider messurements
divider = 3;

//Screwhole size
hole_size = 3;

//Cylinder faces
faces = 50;

//How many sensors?
repeat = 5;

//Spacing distance for cylinder to make code shorter in length
space = divider+cutout_length;

//Calculates length of body and assigns value to variable length
length = ((divider+cutout_length)*repeat)+divider;

difference() {
    //Make body
    cube([repeat*cutout_length+(repeat+1)*divider,depth,height]);
    
    //Make cutouts and screw holes
    for (i = [1 : repeat]) {
        
        //Cutouts
        translate([(divider*i)+(cutout_length*(i-1)),0,0])
            cube([cutout_length,depth,cutout_height]);
            
        //Screw holes
        translate([space*i-cutout_length/2, depth/2, cutout_height])
            cylinder(h=height-cutout_height, d=hole_size, $fn=faces);
    }
}

//Make handles
handle_offset = 5;

/*
//Handle 1
translate([handle_offset*-1, 0, cutout_height])
    cube([handle_offset, depth, height-cutout_height]);

translate([handle_offset*-1, depth/2, cutout_height])
    cylinder(h=height-cutout_height, r=depth/2, $fn=faces);

//Handle 2
translate([length, 0, cutout_height])
    cube([handle_offset, depth, height-cutout_height]);

translate([length+handle_offset, depth/2, cutout_height])
    cylinder(h=height-cutout_height, r=depth/2, $fn=faces);
*/