class Sprite {
    constructor(data, size) {
        this.width = data[2]
        this.height = data[3]

        this.left = data[0] * size
        this.top = data[1] * size
        this.right = (data[0] + this.width) * size
        this.bottom = (data[1] + this.height) * size

        if (data.length > 4) {
            this.ox = data[4]
            this.oy = data[5]
        } else {
            this.ox = 0
            this.oy = 0
        }
    }
    static Build(left, top, width, height, sheet_size) {
        return [
            left * sheet_size,
            top * sheet_size,
            (left + width) * sheet_size,
            (top + height) * sheet_size
        ]
    }
}