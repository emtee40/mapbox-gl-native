#pragma once

#include <mbgl/renderer/render_layer.hpp>
#include <mbgl/style/layers/background_layer_impl.hpp>
#include <mbgl/style/layers/background_layer_properties.hpp>

namespace mbgl {

class RenderBackgroundLayer: public RenderLayer {
public:
    RenderBackgroundLayer(Immutable<style::BackgroundLayer::Impl>);
    ~RenderBackgroundLayer() final = default;

    void transition(const TransitionParameters&) override;
    void evaluate(const PropertyEvaluationParameters&) override;
    bool hasTransition() const override;
    bool hasCrossfade() const override;
    optional<Color> getSolidBackground() const final;
    void render(PaintParameters&, RenderSource*) override;

    std::unique_ptr<Bucket> createBucket(const BucketParameters&, const std::vector<const RenderLayer*>&) const override;

    // Paint properties
    style::BackgroundPaintProperties::Unevaluated unevaluated;
    style::BackgroundPaintProperties::PossiblyEvaluated evaluated;

    const style::BackgroundLayer::Impl& impl() const;
private:
    CrossfadeParameters crossfade;
};

} // namespace mbgl
