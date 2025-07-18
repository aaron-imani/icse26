from pathlib import Path
from comment_removal.nirjas import get_comment_types
import json

cur_dir = Path(__file__).parent.resolve()

input_dir = cur_dir / "filtered_dataset" / 'codenet'

all_files = list(input_dir.joinpath('Java', "Code").iterdir())
snippets = {}

snippets['comment'] = [
    snippet
    for snippet in all_files
    if 'commented' in snippet.name
]

print(f"Found {len(snippets['comment'])} Java snippets in {input_dir}")

snippets['javadoc'] = []
snippets['multiline'] = []
snippets['inline'] = []

for snippet in snippets['comment']:
    print(f"Processing {snippet.name}")
    with open(snippet, 'r', encoding='utf-8') as f:
        code = f.read()
    
    comment_types = get_comment_types(code)
    
    if comment_types['javadoc']:
        snippets['javadoc'].append(snippet.name)
    elif comment_types['multiline']:
        snippets['multiline'].append(snippet.name)
    elif comment_types['inline']:
        snippets['inline'].append(snippet.name)


snippets['comment'] = [snippet.name for snippet in snippets['comment']]

# Save the splits to a JSON file
output_file = cur_dir / "codenet_comment_splits.json"
with open(output_file, 'w', encoding='utf-8') as f:
    json.dump(snippets, f, indent=4)
print(f"Splits saved to {output_file}")

for key, value in snippets.items():
    print(f"{key}: {len(value)} snippets")