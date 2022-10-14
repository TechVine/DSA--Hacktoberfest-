public class linkedList {
	node head = null;
	static class node {
		int val;
		node next;

		public node(int val)
		{
			this.val = val;
		}
	}

	node sortedMerge(node a, node b)
	{
		node result = null;
		/* Base cases */
		if (a == null)
			return b;
		if (b == null)
			return a;
		if (a.val <= b.val) {
			result = a;
			result.next = sortedMerge(a.next, b);
		}
		else {
			result = b;
			result.next = sortedMerge(a, b.next);
		}
		return result;
	}

	node mergeSort(node h)
	{
		if (h == null || h.next == null) {
			return h;
		}

		// mid
		node middle = getMiddle(h);
		node nextofmiddle = middle.next;

		middle.next = null;

		//  mergeSort on left list
		node left = mergeSort(h);

		// mergeSort on right list
		node right = mergeSort(nextofmiddle);

		node sortedlist = sortedMerge(left, right);
		return sortedlist;
	}
	node getMiddle(node h)
	{
		if (h == null)
			return h;
		node fastptr = h.next;
		node slowptr = h;
		while (fastptr != null) {
			fastptr = fastptr.next;
			if (fastptr != null) {
				slowptr = slowptr.next;
				fastptr = fastptr.next;
			}
		}
		return slowptr;
	}

	void push(int new_data)
	{
		node new_node = new node(new_data);
		new_node.next = head;

		head = new_node;
	}

// print linked list
	void printList(node headref)
	{
		while (headref != null) {
			System.out.print(headref.val + " ");
			headref = headref.next;
		}
	}

	public static void main(String[] args)
	{
		linkedList li = new linkedList();
		li.push(26);
		li.push(12);
		li.push(3);
		li.push(18);
		li.push(1);
		li.push(4);
	   // merge Sort
		li.head = li.mergeSort(li.head);
		System.out.print("Sorted Linked List: \n");
		li.printList(li.head);
	}
}

// code by Rufus paul

