import junit.framework.TestCase;

import java.util.Arrays;
import java.util.List;
import java.util.logging.Logger;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!


public class UrlValidatorTest extends TestCase {
	private static final Logger LOGGER = Logger.getLogger(
			UrlValidatorTest.class.getName());



	public UrlValidatorTest(String testName) {
		super(testName);
	}


	public void testManualTest() {
	//You can use this function to implement your manual testing

		UrlValidator urlVal = new UrlValidator(
				null,
				null,
				UrlValidator.ALLOW_ALL_SCHEMES);
		boolean expected;
		boolean result;

		// test case 1: http://
		String url2 = "https://oregonstate.instructure.com/courses/1692917/assignments";
		String url3 = "https://oregonstate.instructure.com/";
		String url4 = "https://bandcamp.com/?show=306";
		String url5 = "https://www.google.com/t123?action=edit&mode=up";
		String url1 = "https://stackoverflow.com/questions/85190/how-does-the-java-for-each-loop-work";
		List<String> testUrls = Arrays.asList(url2, url3, url4, url5, url1);

		expected = true;
		for (int i = 0; i < testUrls.size(); i++) {
			String url = testUrls.get(i);
			LOGGER.info("testing: " + url);

			result = urlVal.isValid(url);

			LOGGER.info("protocol: " + i + " -> " + result);
			assertEquals(url, expected, result);

		}
	}

	public void testYourFirstPartition() {
		// Testing protocol

		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		String url1;
		boolean expected;
		boolean result;

		// test case 1: http://
		url1 = "http://www.google.com:80/t123?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);

		LOGGER.info("protocol: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 2: ftp://
		url1 = "ftp://www.google.com:80/t123?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("protocol: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 3: no protocol
		url1 = "www.google.com:80/t123?action=edit&mode=up";
		expected = false;
		result = urlVal.isValid(url1);
		LOGGER.info("protocol: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 4: invalid protocol
		url1 = "://www.google.com:80/t123?action=edit&mode=up";
		expected = false;
		result = urlVal.isValid(url1);
		LOGGER.info("protocol: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 5: https://
		url1 = "https://www.google.com:80/t123?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("protocol: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);
	}

	public void testYourSecondPartition() {
		// Testing IP Address

		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		String url1;
		boolean expected;
		boolean result;

		// test case 1: 255.255.255.255
		url1 = "http://255.255.255.255:80/t123?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		//System.out.println("ip address: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 2: 255.255.255.256
		url1 = "http://255.255.255.256:80/t123?action=edit&mode=up";
		expected = false;
		result = urlVal.isValid(url1);
		LOGGER.info("ip address: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 3: no ip address or domain
		url1 = "http://:80/t123?action=edit&mode=up";
		expected = false;
		result = urlVal.isValid(url1);
		LOGGER.info("ip address: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);
	}

	public void testYourThirdPartition() {
		// Testing subdomain

		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		String url1;
		boolean expected;
		boolean result;

		// test case 1: www
		url1 = "http://www.google.com:80/t123?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("subdomain: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 2: aws
		url1 = "http://aws.amazon.com:80/t123?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("subdomain: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 3: no subdomain
		url1 = "http://google.com:80/t123?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("subdomain: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 4: bad subdomain
		url1 = "http://76badsubdomain$%.google.com:80/t123?action=edit&mode=up";
		expected = false;
		result = urlVal.isValid(url1);
		LOGGER.info("subdomain: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);
	}

	public void testYourFourthPartition() {
		// Testing top level domain

		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		String url1;
		boolean expected;
		boolean result;

		// test case 1: com
		url1 = "http://www.google.com:80/t123?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("TLD: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 2: edu
		url1 = "http://oregonstate.edu:80/t123?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("TLD: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 3: no TLD 
		url1 = "http://www.google.:80/t123?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("TLD: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 4: bad TLD 
		url1 = "http://www.google.badTLD45#$:80/t123?action=edit&mode=up";
		expected = false;
		result = urlVal.isValid(url1);
		LOGGER.info("TLD: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);
	}

	public void testYourFifthPartition() {
		// Testing domain

		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		String url1;
		boolean expected;
		boolean result;

		// test case 1: google
		url1 = "http://www.google.com:80/t123?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("domain: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 2: amazon
		url1 = "http://www.amazon.com:80/t123?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("domain: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 3: no domain
		url1 = "http://www..com:80/t123?action=edit&mode=up";
		expected = false;
		result = urlVal.isValid(url1);
		LOGGER.info("domain: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 4: bad domain
		url1 = "http://www.gt72*(-.com:80/t123?action=edit&mode=up";
		expected = false;
		result = urlVal.isValid(url1);
		LOGGER.info("domain: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);
	}

	public void testYourSixthPartition() {
		// Testing port

		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		String url1;
		boolean expected;
		boolean result;

		// test case 1: 80
		url1 = "http://www.google.com:80/t123?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("port: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 2: 0
		url1 = "http://www.google.com:0/t123?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("port: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 3: 65535
		url1 = "http://www.google.com:65535/t123?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("port: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 4: 65536
		url1 = "http://www.google.com:65536/t123?action=edit&mode=up";
		expected = false;
		result = urlVal.isValid(url1);
		LOGGER.info("port: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 5: -1
		url1 = "http://www.google.com:-1/t123?action=edit&mode=up";
		expected = false;
		result = urlVal.isValid(url1);
		LOGGER.info("port: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 6: no port
		url1 = "http://www.google.com/t123?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("port: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);
	}

	public void testYourSeventhPartition() {
		// Testing path

		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		String url1;
		boolean expected;
		boolean result;

		// test case 1: /t123
		url1 = "http://www.google.com:80/t123?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("port: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 2: /test1
		url1 = "http://www.google.com:80/test1?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("port: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 3: /..
		url1 = "http://www.google.com:80/..?action=edit&mode=up";
		expected = false;
		result = urlVal.isValid(url1);
		LOGGER.info("port: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 4: /$23//
		url1 = "http://www.google.com:80/$23//?action=edit&mode=up";
		expected = false;
		result = urlVal.isValid(url1);
		LOGGER.info("port: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 5: no path
		url1 = "http://www.google.com:80?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("port: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);
	}

	public void testYourEighthPartition() {
		// Testing query

		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		String url1;
		boolean expected;
		boolean result;

		// test case 1: ?action=edit&mode=up
		url1 = "http://www.google.com:80/t123?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("query: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 2: ?4hi32*@idf
		url1 = "http://www.google.com:80/t123?4hi32*@idf";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("query: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 3: no query
		url1 = "http://www.google.com:80/t123";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("query: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);
	}

	public void testYourNinthPartition() {
		// Testing absence of authority (subdomain + domain + TLD)

		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		String url1;
		boolean expected;
		boolean result;

		// test case 1: www.google.com
		url1 = "http://www.google.com:80/t123?action=edit&mode=up";
		expected = true;
		result = urlVal.isValid(url1);
		LOGGER.info("authority: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);

		// test case 2: no authority
		url1 = "http://:80/t123?action=edit&mode=up";
		expected = false;
		result = urlVal.isValid(url1);
		LOGGER.info("authority: " + url1 + " -> " + result);
		assertEquals(url1, expected, result);
	}

	public void testIsValid() {
		// You can use this function for programming based testing

	}


}
