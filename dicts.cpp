#include "carros.h"

const Carros::hpGain Carros::turbos[] = {
  {"MasterPr 550-AH", 280}, {"Precision 650-LS", 360},
  {"Garrett 750-XT", 450}, {"2x MasterPr 550-AH", 500},
  {"2x Precision 650-LS", 670}, {"2x Garrett 750-XT", 840}
};

const Carros::hpResis Carros::internals[] = {
  {"Piston RP-650, Rod XXt-700", 640},
  {"Piston RP-800, Rod XXt-790", 780},
  {"Piston RP-1000, Rod XXt-970", 970},
  {"Piston RP-1300, Rod XXt-1320, Forged Crankshaft", 1290},
  {"Piston RP-1650, Rod XXt-1640, Billet Crankshaft", 1630},
  {"Piston RP-2000+, Rod XXt-2000+, Billet Crankshaft, Billet Block", 2500}
};

const Carros::hpGain Carros::intake[] = {
  {"2 inch intake, Sport Filter, Original Head", 30},
  {"2.5 inch intake, Sport Filter, Original Head w/ Sport Camshaft", 90},
  {"3 inch intake, Racing Filter, CNC Head w/ Sport Camshaft", 165},
  {"3.5 intake w/ flow work, Racing Filter, CNC Head w/ Racing Camshaft", 260}
};

const Carros::hpGain Carros::exaust[] = {
  {"3 inch stainless steel exaust w/ Sport Silencers", 70},
  {"3 inch titanium exaust w/ Racing Silencers", 90},
  {"3.5 inch titanium exaust w/ no Silencers", 110}
};

const Carros::hpGain Carros::eletronics[] = {
  {"Fueltech FT550 w/ Original Harness", 70},
  {"Fueltech FT600 w/ Racing Harness", 100}
};

const Carros::change Carros::trasmission[] = {
  {"Original Trasmission w/ Short Shifter, Sport Clutch", .2},
  {"Sport Trasmission w/ H-Pattern Short Shifter, Sport+ Clutch", .17},
  {"Sport Trasmission w/ Sequential Shifter, Racing Clutch", .14},
  {"Racing Sequential Trasmission w/ Pneumatic Shifter, Racing Clutch", .07}
};

const Carros::gForce Carros::suspension[] = {
  {"Semi-Slick Tires w/ Sport Suspension (shock absorbers, springs)", 0.8},
  {"Semi-Slick Tires w/ Racing Suspension (shock absorbers, springs, bushings etc)", 1},
  {"Slick Tires w/ Full Racing Suspension (coilovers, bushings, stabilizer bars etc)", 1.2}
};

const Carros::gForce Carros::chassis[] = {
  {"Chassis reinforcement w/ Simple Rollcage (screwed)", 0.6},
  {"Chassis reinforcement w/ Simple Rollcage (welded), better aerodynamics", 1.1},
  {"Reinforcement w/ Racing Rollcage (welded), better aerodynamics, locked suspension", 1.6}
};