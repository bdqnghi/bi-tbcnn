import java.io.BufferedWriter;
import java.io.IOException;
import java.math.BigDecimal;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Knapsack {
	public static void main(String[] args) throws IOException {
		final BigDecimal MAX_SIZE = new BigDecimal(20);
		BigDecimal BAGGAGE_SIZE = BigDecimal.ZERO;
		final Path input = Paths.get("input_file.csv");
		final Path output = Paths.get("output_file.csv");

		List<Baggage> list = new ArrayList<>();
		List<Baggage> result = new ArrayList<>();

		try (Stream<String> lines = Files.lines(input)) {
			list = lines.map(s -> new Baggage(s.split(","))).sorted(Comparator.comparing(Baggage::getValue).reversed())
					.collect(Collectors.toList());
		}
		for (Baggage baggage : list) {
			if ((BAGGAGE_SIZE.add(baggage.getSize()).compareTo(MAX_SIZE) < 0)) {
				result.add(baggage);
				BAGGAGE_SIZE = BAGGAGE_SIZE.add(baggage.getSize());
			}
		}
		try (BufferedWriter bw = Files.newBufferedWriter(output)) {
			for (Baggage baggage : result) {
				bw.write(baggage.Property());
				bw.newLine();
			}
		}
	}

}

class Baggage {
	final private String name;
	final private BigDecimal size;
	final private BigDecimal weight;
	final private BigDecimal value;

	Baggage(String[] baggage) {
		this.name = baggage[0];
		this.size = new BigDecimal(baggage[1]);
		this.weight = new BigDecimal(baggage[2]);
		this.value = this.weight.divide(this.size, BigDecimal.ROUND_HALF_EVEN);
	}

	public BigDecimal getValue() {
		return this.value;
	}

	public BigDecimal getSize() {
		return this.size;
	}

	public String Property() {
		return String.format("%s,%s,%s", name, size, weight);
	}
}
