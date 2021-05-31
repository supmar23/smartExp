package smartExp;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.block.BlockBorder;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.chart.plot.XYPlot;
import org.jfree.chart.renderer.xy.XYLineAndShapeRenderer;
import org.jfree.chart.title.TextTitle;
import org.jfree.data.xy.XYDataset;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;
import javax.swing.*;
import java.awt.*;

public class GUI extends JFrame {
	private static final long serialVersionUID = -9121276679880338370L;
	private XYSeries series1 = new XYSeries("speed (m/s)");
	private XYSeries series2 = new XYSeries("acceleration (m/s^2)");

	public GUI() {
        initUI();
    }

    private void initUI() {
        XYDataset dataset = createDataset();
        JFreeChart chart = createChart(dataset);

        ChartPanel chartPanel = new ChartPanel(chart);
        chartPanel.setBorder(BorderFactory.createEmptyBorder(15, 15, 15, 15));
        chartPanel.setBackground(Color.white);
        
        add(chartPanel);

        pack();
        setTitle("Experiment data");
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    
    public void addValueToDataset1(String time, String speed) {
    	float t = Float.parseFloat(time);
    	float s = Float.parseFloat(speed);
    	series1.add(t, s);
    }
    
    public void addValueToDataset2(String time, String acc) {
    	float t = Float.parseFloat(time);
    	float a = Float.parseFloat(acc);
    	series2.add(t, a);
    }

    private XYDataset createDataset() {
        var dataset = new XYSeriesCollection();
        dataset.addSeries(series1);
        dataset.addSeries(series2);

        return dataset;
    }

    private JFreeChart createChart(XYDataset dataset) {
        JFreeChart chart = ChartFactory.createXYLineChart(
                "Speed",
                "Time in seconds",
                "Speed / Acceleration",
                dataset,
                PlotOrientation.VERTICAL,
                true,
                true,
                false
        );

        XYPlot plot = chart.getXYPlot();

        var renderer = new XYLineAndShapeRenderer();
        
        renderer.setSeriesPaint(0, Color.RED);
        renderer.setSeriesStroke(0, new BasicStroke(2.0f));
        renderer.setSeriesPaint(1, Color.BLUE);
        renderer.setSeriesStroke(1, new BasicStroke(2.0f));

        plot.setRenderer(renderer);
        plot.setBackgroundPaint(Color.white);

        plot.setRangeGridlinesVisible(true);
        plot.setRangeGridlinePaint(Color.BLACK);

        plot.setDomainGridlinesVisible(true);
        plot.setDomainGridlinePaint(Color.BLACK);

        chart.getLegend().setFrame(BlockBorder.NONE);

        chart.setTitle(new TextTitle("Speed and Acceleration Graphics",
                        new Font("Serif", java.awt.Font.BOLD, 18)
                )
        );

        return chart;
    }
}
