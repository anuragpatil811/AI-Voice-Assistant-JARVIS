from googlesearch import search

def search_google(task):
    results = []
    for result in search(task, num_results=5):
        results.append(result)
    return results[0] if results else "No results found"
