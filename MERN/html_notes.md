# HTML Notes

---

## 1. Basics

- HTML = HyperText Markup Language — structure of web pages
- Not a programming language, it's a **markup language**
- HTML → structure | CSS → style | JS → behaviour

### Minimal Page
```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Page Title</title>
</head>
<body>
  <h1>Hello World</h1>
</body>
</html>
```

---

## 2. Key Concepts

### Block vs Inline
| Block | Inline |
|-------|--------|
| New line, full width | Flows with text |
| `<div>`, `<p>`, `<h1>` | `<span>`, `<a>`, `<strong>` |

### Void Elements (no closing tag)
`<br>` `<hr>` `<img>` `<input>` `<meta>` `<link>`

### Boolean Attributes
```html
<input disabled>
<input readonly>
<input checked>
<video autoplay muted loop>
```

---

## 3. Important Tags

```html
<!-- Text -->
<strong>important</strong>   <!-- semantic bold -->
<em>emphasis</em>            <!-- semantic italic -->
<mark>highlight</mark>
<del>deleted</del>
<code>inline code</code>
<abbr title="HyperText">HTML</abbr>

<!-- Links -->
<a href="https://example.com" target="_blank" rel="noopener noreferrer">Link</a>
<a href="#section-id">Anchor</a>
<a href="mailto:a@b.com">Email</a>
<a href="/file.pdf" download>Download</a>

<!-- Image -->
<img src="photo.jpg" alt="description" width="800" height="600" loading="lazy">

<!-- Lists -->
<ul><li>Unordered</li></ul>
<ol type="1" start="1"><li>Ordered</li></ol>
<dl><dt>Term</dt><dd>Definition</dd></dl>
```

---

## 4. Semantic HTML5

Use these instead of `<div>` wherever possible:

```html
<header>   <!-- site/section header -->
<nav>      <!-- navigation links -->
<main>     <!-- primary content (one per page) -->
<article>  <!-- self-contained content (blog post) -->
<section>  <!-- thematic group with heading -->
<aside>    <!-- sidebar / related content -->
<footer>   <!-- site/section footer -->
<figure> + <figcaption>
<time datetime="2024-03-18">March 18</time>
<details><summary>Click to expand</summary>hidden</details>
```

**article vs section vs div:**
- `<article>` → can stand alone (RSS-worthy?)
- `<section>` → has a heading, part of a whole
- `<div>` → no semantic meaning, styling only

---

## 5. Forms

```html
<form action="/submit" method="POST" enctype="multipart/form-data">
  <label for="name">Name:</label>
  <input type="text" id="name" name="name" required minlength="2">

  <input type="email"    placeholder="Email">
  <input type="password" minlength="8">
  <input type="number"   min="0" max="100">
  <input type="date">
  <input type="file"     accept=".pdf" multiple>
  <input type="checkbox" checked>
  <input type="radio"    name="gender" value="m">
  <input type="hidden"   name="csrf" value="TOKEN">

  <textarea rows="4" name="msg"></textarea>

  <select name="lang">
    <option value="cpp">C++</option>
    <option value="py" selected>Python</option>
  </select>

  <button type="submit">Submit</button>
  <button type="reset">Reset</button>
  <button type="button" onclick="doSomething()">Click</button>
</form>
```

**GET vs POST:**
- GET → data in URL, use for search/filter
- POST → data in body, use for login/register/upload

---

## 6. Meta Tags (Head)

```html
<meta charset="UTF-8">                          <!-- always first -->
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta name="description" content="Page desc">
<meta name="robots" content="noindex, nofollow">

<!-- Open Graph (social preview) -->
<meta property="og:title" content="Title">
<meta property="og:image" content="img.jpg">
```

---

## 7. Script Loading

```html
<script src="app.js"></script>          <!-- blocks parsing -->
<script src="app.js" defer></script>    <!-- runs after DOM ready (preferred) -->
<script src="lib.js" async></script>    <!-- runs ASAP, order not guaranteed -->
```
**Rule:** Use `defer` for your own scripts, `async` for independent 3rd-party scripts.

---

## 8. Accessibility (a11y)

```html
<!-- Always link labels -->
<label for="email">Email:</label>
<input id="email" type="email">

<!-- ARIA for custom widgets -->
<button aria-label="Close">✕</button>
<button aria-expanded="false">Menu</button>
<div aria-live="polite">Loading...</div>
<span aria-hidden="true">🎉</span>   <!-- decorative, skip for screen reader -->
```

---

## 9. data-* Attributes

```html
<button data-user-id="42" data-action="delete">Delete</button>
```
```js
btn.dataset.userId   // "42"   (hyphen-case → camelCase)
btn.dataset.action   // "delete"
```

---

## 10. Common Interview Questions

| Question | Key Point |
|----------|-----------|
| `<b>` vs `<strong>` | Same look, `<strong>` has semantic importance |
| `id` vs `class` | id = unique, class = reusable group |
| `async` vs `defer` | async runs ASAP, defer runs after DOM parsed |
| GET vs POST | GET = URL params, POST = request body |
| `alt` on `<img>` | Accessibility + SEO + fallback if image fails |
| `rel="noopener noreferrer"` | Prevents reverse tabnapping via `window.opener` |
| `localStorage` vs `sessionStorage` | session clears on tab close; local persists |
| `<article>` vs `<section>` | article = standalone; section = themed group |
| Void elements | `<br>` `<img>` `<input>` — no closing tag |
| Canvas vs SVG | Canvas = pixel/JS; SVG = vector/DOM |
