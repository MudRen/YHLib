inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
����ѩɽ�µ�ɮ��Ϊ�˷���������ԭ���ص������˵��ܵ�
�Ա���֪��������������
LONG);

        set("exits", ([
                "up"   : __DIR__"dangpu",
                "west" : __DIR__"xsmidao1",
        ]));

	setup();
        replace_program(ROOM);
}
