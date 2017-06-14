#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSoundEffect>

#include "gui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	
	void refreshPalette();
	void refresh_lighting_buttons();
	void SetCurrentColor(const QColor &fillColor);
	
private:
	qreal stringLight;
	qreal stringDark;
	bool enableLighting;
	QColor ambientColor;
	qreal ambientColorBrightness;
	qreal alpha;
	int mixString;
	QSoundEffect controlClick;

private slots:
	void on_btnSaveJPG_clicked();
	void on_btnClipboard_clicked();

	void on_btnSaveJPG_pressed();
	void on_btnClipboard_pressed();

	void on_backgroundSlider_sliderMoved(int position);

	void on_lightSlider_sliderMoved(int position);
	void on_darkSlider_sliderMoved(int position);
	void on_brightnessSlider_sliderMoved(int position);
	void on_alphaSlider_sliderMoved(int position);

	void on_colorWheel_selectedColorsChanged();
	void on_colorWheel_hoverColor(const QColor &color);
	void on_colorWheel_lightingColorChanged(const QColor &color);

	void on_visualPalette_hoverColor(const QColor &color);

	void on_rdoGamutShapeTriangle_clicked(bool checked = false);
	void on_rdoGamutShapeLine_clicked(bool checked = false);
	void on_rdoGamutShapeSquare_clicked(bool checked = false);

	void on_rdoMixString1_clicked(bool checked = false);
	void on_rdoMixString3_clicked(bool checked = false);
	void on_rdoMixString5_clicked(bool checked = false);

	void on_rdoCourseWheel_clicked(bool checked = false);
	void on_rdoFineWheel_clicked(bool checked = false);

	void on_btnLightingOn_clicked(bool checked = false);
	void on_btnLightingOff_clicked(bool checked = false);

private:
	//bool eventFilter( QObject* watched, QEvent* event );
	void refresh_mixString_buttons(void);
	void refresh_gamutShape_buttons(void);
	void refresh_wheel_buttons(void);

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
