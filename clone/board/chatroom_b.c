// /clone/board/chatroom_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���������԰�", ({ "board" }));
	set("long", "��Ҷ������ˮ��һ��˵�ϻ���\n" );
	set("capacity", 100);
        // not setup now
        // I will call setup after set from me
}

void set_from_me(object me, object chatroom)
{
        if (query("board_id"))
                return 0;

        if (! geteuid(me))
                return 0;

        set("board_id", "chatroom_" + geteuid(me));
        set_name(me->name(1) + "�����԰�", ({ "board" }));
	set("capacity", 100 + (int)me->query_skill("idle-force", 1));
        setup();
        move(chatroom);
}

int do_discard(string arg)
{
	mapping *notes;
	int num;

	if (! arg || sscanf(arg, "%d", num) != 1)
		return notify_fail("ָ���ʽ��discard <���Ա��>\n");
	notes = query("notes");
	if (! arrayp(notes) || num < 1 || num > sizeof(notes))
		return notify_fail("û���������ԡ�\n");
	num--;
	if (notes[num]["author"] != (string) this_player(1)->query("name") + "-" +
                                    this_player(1)->query("id")
        &&      ! environment()->is_owner(this_player(1))
	&&	(string)SECURITY_D->get_status(this_player(1)) != "(admin)"
	&&      (string)SECURITY_D->get_status(this_player(1)) != "(arch)")
        {
		write("������Բ�����д�ģ���Ҳ������������ҵ��ϴ�\n");
                return 1;
        }

	notes = notes[0..num - 1] + notes[num + 1..sizeof(notes) - 1];
	set("notes", notes);
	save();
	write("ɾ���� " + (num+1) + " ������....Ok��\n");
	return 1;
}
