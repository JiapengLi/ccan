#include <ccan/tlist2/tlist2.h>

struct child {
	const char *name;
	struct list_node list;
};

struct cousin {
	const char *name;
	struct list_node list;
};

int main(int argc, char *argv[])
{
	TLIST2(struct child, list) children;
	struct child child = { "child" };
#ifdef FAIL
#if !HAVE_FLEXIBLE_ARRAY_MEMBER
#error Need flexible array members to check type
#endif
	struct cousin *c;
#else
	struct child *c;
#endif

	tlist2_init(&children);
	tlist2_add(&children, &child);

	tlist2_for_each(&children, c)
		(void) c; /* Suppress unused-but-set-variable warning. */
	return 0;
}
