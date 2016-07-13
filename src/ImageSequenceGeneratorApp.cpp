#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"

#include "CinderOpenCv.h"

using namespace ci;
using namespace ci::app;

class ImageSequenceGeneratorApp : public App {
  public:
	void setup() override;
	void draw() override;
	
	gl::TextureRef	mTexture;
};

void ImageSequenceGeneratorApp::setup()
{
	ci::Surface8u surface( loadImage( loadAsset( "p0001.jpg" ) ) );
	cv::Mat input( toOcv( surface ) );
	cv::Mat output;

	cv::medianBlur( input, output, 11 );
//	cv::Sobel( input, output, CV_8U, 0, 1 ); 
//	cv::threshold( input, output, 128, 255, CV_8U );

	mTexture = gl::Texture::create( fromOcv( output ) );
}   

void ImageSequenceGeneratorApp::draw()
{
	gl::clear();
	gl::draw( mTexture );
}

CINDER_APP( ImageSequenceGeneratorApp, RendererGl )
