inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
����ѩɽ�µ�ɮ��Ϊ�˷���������ԭ���ص������˵��ܵ�
�Ա���֪��������������
LONG);

        set("exits", ([
                "east"  : __DIR__"xsmidao1",
                "south" : __DIR__"xsmidao3",
        ]));

	setup();
        replace_program(ROOM);
}
