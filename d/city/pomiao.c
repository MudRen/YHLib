inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ���������õ������������ưܲ���������������
��һ�ԣ����ϵ���Ҳ�����˻ҳ���һ����֪���Ѿ��ܾ�û����
��������ˡ����з��Ÿ����㰸���������ҵ����ż���ʣ�µ�
����ͷ��ؤ�ｭ�Ϸֶ�ͱ����ڴ˴���
LONG);
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"ml4",
		"enter" : __DIR__"gbxiaowu",
	]));
	set("objects", ([
		CLASS_D("gaibang") + "/lu" : 1,
		CLASS_D("gaibang") + "/peng" : 1,
	]));
	setup();
	"/clone/board/gaibang_b"->foo();
}

int valid_leave(object me, string dir)
{
        object guard;

        if (dir != "enter"
           || ! objectp(guard = present("lu youjiao", this_object()))
           && ! objectp(guard = present("peng youjing", this_object())))
                return ::valid_leave(me, dir);

        return guard->permit_pass(me, dir);
}
