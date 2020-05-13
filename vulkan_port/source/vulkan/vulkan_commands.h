#ifndef VULKAN_COMMAND_POOL_H
#define VULKAN_COMMAND_POOL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <vulkan/vulkan.h>

#include "core/fileio.h"
#include "core/mem.h"

#include "vulkan_struct.h"

VkCommandBuffer vk_begin_single_time_commands(vulkan_state *vk_state, struct vulkan_renderer *vk_renderer);
void vk_end_single_time_commands(vulkan_state *vk_state, struct vulkan_renderer *vk_renderer, VkCommandBuffer command_buffer);
void vk_create_command_pool(vulkan_state *vk_state, struct vulkan_renderer *vk_renderer);
void vk_create_command_buffers(vulkan_state *vk_state, struct vulkan_renderer *vk_renderer, struct vulkan_pipeline *vk_pipeline);
void vk_create_semaphores(vulkan_state *vk_state, struct vulkan_renderer *vk_renderer);

#endif