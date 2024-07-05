package org.example;

import org.apache.commons.lang3.tuple.Pair;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;
import java.util.Objects;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ForkJoinPool;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {

    public static void convert() {
        List<Path> files = null;
        Path source = Path.of("src/main/resources/input");

        try (Stream<Path> stream = Files.list(source)) {
            files = stream.collect(Collectors.toList());
        } catch (IOException ex) {
            System.out.println("Error while loading files");
        }

        if (files == null) {
            return;
        }
        Stream<Path> filesStream = files.parallelStream();

        Stream<Pair<String, BufferedImage>> imgsStream = filesStream.map(path -> {
            try {
                BufferedImage image = ImageIO.read(path.toFile());
                String name = String.valueOf(path.getFileName());
                return Pair.of(name, image);
            } catch (IOException e) {
                e.printStackTrace();
                return null;
            }
        }).filter(Objects::nonNull).parallel();

        Stream<Pair<String, BufferedImage>> convertedImgs = imgsStream.map(pair -> {
                    BufferedImage original = pair.getValue();
                    BufferedImage result = new BufferedImage(original.getWidth(), original.getHeight(), original.getType());


            for (int i = 0; i < original.getWidth(); i++) {
                for (int j = 0; j < original.getHeight(); j++) {
                    changeColorsAndFlip(original, result, i, j);
                }
            }

            return Pair.of(pair.getKey(), result);
        }).parallel();

        convertedImgs.forEach(pair -> {
            try {
                String dirPath = "src/main/resources/output";
                File dir = new File("src/main/resources/output");
                if (!dir.exists()) {
                    dir.mkdirs();
                }

                File outputFile = new File(dirPath + "/" + pair.getKey());
                ImageIO.write(pair.getValue(), "jpg", outputFile);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        });
    }

    private static void changeColorsAndFlip(BufferedImage original, BufferedImage result, int i, int j) {
        int rgb = original.getRGB(i, j);
        Color color = new Color(rgb);
        int red = color.getGreen();
        int blue = color.getRed();
        int green = color.getBlue();
        Color outColor = new Color(red, green, blue);
        result.setRGB(i, original.getHeight() - j - 1, outColor.getRGB());
    }

    public static void warmUp() throws ExecutionException, InterruptedException {
        ForkJoinPool fjp = null;
        fjp = new ForkJoinPool(8);
        for (int j = 0; j < 3; j++) {
            fjp.submit(Main::convert).get();
        }
        fjp.shutdown();
    }

    public static void main(String[] args) throws ExecutionException, InterruptedException {
        long time;
        ForkJoinPool fjp = null;

        System.out.println("Warming up :)");
        warmUp();

        System.out.println("\n\nTimes:");
        for (int i = 8; i >= 1; i /= 2) {
            fjp = new ForkJoinPool(i);
            for (int j = 0; j < 3; j++) {
                time = System.currentTimeMillis();
                fjp.submit(Main::convert).get();
                System.out.println(i + " Threads - " + (System.currentTimeMillis() - time));
            }
            fjp.shutdown();
            System.out.println("");
        }
    }
}