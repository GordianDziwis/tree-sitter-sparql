import XCTest
import SwiftTreeSitter
import TreeSitterSparql

final class TreeSitterSparqlTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_sparql())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading SPARQL grammar")
    }
}
