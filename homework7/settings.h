#ifndef SETTINGS_H
#define SETTINGS_H

class Settings 
{
	public:
		Settings();
		Settings(int width, int height,double bgColorR,double bgColorG,double bgColorB);

		
		int getWidth() const;
	
		int getHeight() const;
		
		float getAspectRatio() const;

	
		void setBgColor(double bgColorR,double bgColorG,double ColorB);
		void setWidth(int newWidth);
		void setHeight(int newHeight);

	private:
		double bgColorR;
		double bgColorG;
		double bgColorB;
		int imgWidth;
		int imgHeight;

};
Settings::Settings()
{
	imgWidth = 1920;
	imgHeight = 1080;
	bgColorR = 0;
	bgColorG = 0;
	bgColorB = 0;
}
Settings::Settings(int width,int height,double bgColorR,double bgColorG,double bgColorB)
{
	width = imgWidth;
	height = imgHeight;
	bgColorR = bgColorR;
	bgColorG = bgColorG;
	bgColorB = bgColorB;
}
	

	int Settings::getWidth() const {
		return imgWidth;
	}

	int Settings::getHeight() const	{
		return imgHeight;
	}

	float Settings::getAspectRatio() const {
		return (double)imgWidth/(double)imgHeight;
	}

	void Settings::setBgColor(double bgColorR,double bgColorG,double bgColorB)	{
		bgColorR = bgColorR;
		bgColorG = bgColorG;
		bgColorB = bgColorB;
	}

	void Settings::setWidth(int newWidth)	{
		imgWidth = newWidth;
	}

	void Settings::setHeight(int newHeight)	{
		imgHeight = newHeight;
	}


#endif
