#include "hud.h"

struct hud *create_hud(struct vulkan_state *vk_state, struct vulkan_base *vk_base, struct vulkan_pipeline *pipeline) {

    struct hud *self = safe_calloc(1, sizeof(struct hud));

    self->pipeline = pipeline;

    vulkan_pipeline_initialize(vk_state, vk_base, pipeline);

    return self;
}

void render_hud(struct vulkan_state *vk_state, struct vulkan_base *vk_base, struct hud *self, VkCommandBuffer command_buffer, uint32_t image_index) {

    vulkan_pipeline_draw(self->pipeline, self->pipeline->renderbuffer, command_buffer, image_index);

    struct uniform_buffer_object ubo = {0};

    float view[16];
    float ortho[16];

    matrix_identity(view);

    float width = (float)vk_base->swapchain->swapchain_extent.width;
    float height = (float)vk_base->swapchain->swapchain_extent.height;
    matrix_orthographic(ortho, 0, width, 0, height, 0, 1);

    matrix_multiply(ubo.mvp, ortho, view);

    vk_update_uniform_buffer(vk_state, self->pipeline, image_index, ubo);
}

void delete_hud(vulkan_state *vk_state, struct hud *self) {

    delete_vulkan_pipeline(vk_state, self->pipeline);

    free(self);
}
