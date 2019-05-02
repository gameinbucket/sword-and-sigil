package main

import (
	"./graphics"
	"./render"
)

// Constants
const (
	Gravity = 0.01

	AnimationRate = 16

	AnimationNotDone    = 0
	AnimationAlmostDone = 1
	AnimationDone       = 2

	AnimationFront     = 0
	AnimationFrontSide = 1
	AnimationSide      = 2
	AnimationBackSide  = 3
	AnimationBack      = 4

	DirectionNorth     = 0
	DirectionNorthEast = 1
	DirectionEast      = 2
	DirectionSouthEast = 3
	DirectionSouth     = 4
	DirectionSouthWest = 5
	DirectionWest      = 6
	DirectionNorthWest = 7
	DirectionCount     = 8
	DirectionNone      = 8

	HumanUID  = uint16(0)
	BaronUID  = uint16(1)
	TreeUID   = uint16(2)
	PlasmaUID = uint16(3)
	MedkitUID = uint16(4)
)

// Variables
var (
	DirectionToAngle = []float32{
		0.0 * DegToRad,
		45.0 * DegToRad,
		90.0 * DegToRad,
		135.0 * DegToRad,
		180.0 * DegToRad,
		225.0 * DegToRad,
		270.0 * DegToRad,
		315.0 * DegToRad,
	}
)

type thing struct {
	world          *world
	uid            uint16
	sid            string
	nid            uint16
	animation      [][]*render.Sprite
	animationMod   int
	animationFrame int
	x              float32
	y              float32
	z              float32
	angle          float32
	deltaX         float32
	deltaY         float32
	deltaZ         float32
	oldX           float32
	oldY           float32
	oldZ           float32
	netX           float32
	netY           float32
	netZ           float32
	deltaNetX      float32
	deltaNetY      float32
	deltaNetZ      float32
	minBX          int
	minBY          int
	minBZ          int
	maxBX          int
	maxBY          int
	maxBZ          int
	ground         bool
	radius         float32
	height         float32
	speed          float32
	health         uint16
	update         func() bool
	damage         func(uint16)
}

func (me *thing) blockBorders() {
	me.minBX = int((me.x - me.radius) * InverseBlockSize)
	me.minBY = int(me.y * InverseBlockSize)
	me.minBZ = int((me.z - me.radius) * InverseBlockSize)
	me.maxBX = int((me.x + me.radius) * InverseBlockSize)
	me.maxBY = int((me.y + me.height) * InverseBlockSize)
	me.maxBZ = int((me.z + me.radius) * InverseBlockSize)
}

func (me *thing) addToBlocks() {
	for gx := me.minBX; gx <= me.maxBX; gx++ {
		for gy := me.minBY; gy <= me.maxBY; gy++ {
			for gz := me.minBZ; gz <= me.maxBZ; gz++ {
				block := me.world.getBlock(gx, gy, gz)
				block.addThing(me)
			}
		}
	}
}

func (me *thing) removeFromBlocks() {
	for gx := me.minBX; gx <= me.maxBX; gx++ {
		for gy := me.minBY; gy <= me.maxBY; gy++ {
			for gz := me.minBZ; gz <= me.maxBZ; gz++ {
				block := me.world.getBlock(gx, gy, gz)
				block.removeThing(me)
			}
		}
	}
}

func (me *thing) cleanup() {
	me.world.removeThing(me)
	me.removeFromBlocks()
}

func (me *thing) render(spriteBuffer map[string]*graphics.RenderBuffer, camX, camZ, camAngle float32) {

}
