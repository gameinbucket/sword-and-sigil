#include "place.h"

sector *place_flat(renderstate *rs, world *w) {

    texture **textures = rs->textures;

    int vec_count = 4;
    vec **vecs = safe_malloc(vec_count * sizeof(vec *));

    vecs[0] = vec_init(0, 0);
    vecs[1] = vec_init(0, 127);
    vecs[2] = vec_init(127, 127);
    vecs[3] = vec_init(127, 0);

    int line_count = 0;
    line **lines = NULL; // safe_malloc(line_count * sizeof(line *));

    // lines[0] = line_init((vec){0, 0}, (vec){0, 127}, 0, 1, 0);

    sector *s = sector_init(vecs, vec_count, lines, line_count, 0, 0, 10, 0, textures[TEXTURE_PLANK]->id, SECTOR_NO_SURFACE);

    world_add_sector(w, s);

    return s;
}
