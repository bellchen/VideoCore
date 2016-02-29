//
//  MopiVideoFilter.hpp
//  Pods
//
//  Created by wheelswang on 16/2/1.
//
//

#ifndef BeautyVideoFilter_h
#define BeautyVideoFilter_h
#include <videocore/filters/IVideoFilter.hpp>

namespace videocore {
    namespace filters {
        class BeautyVideoFilter : public IVideoFilter {
            
        public:
            BeautyVideoFilter();
            ~BeautyVideoFilter();
            
        public:
            virtual void initialize();
            virtual bool initialized() const { return m_initialized; };
            virtual std::string const name() { return "com.videocore.filters.beauty"; };
            virtual void bind();
            virtual void unbind();
            void setOutputSize(int width, int height);
            
        public:
            
            const char * const vertexKernel() const ;
            const char * const pixelKernel() const ;
            
        private:
            static bool registerFilter();
            static bool s_registered;
        private:
            
            unsigned int m_uMatrix;
            unsigned int m_vao;
            unsigned int m_singleStepOffset;
            unsigned int m_params;
            bool m_initialized;
            bool m_bound;
            int m_width;
            int m_height;
            
        };
    }
}

#endif /* MopiVideoFilter_hpp */
