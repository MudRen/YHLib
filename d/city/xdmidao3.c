inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
����Ѫ���ŵ�ɮ��Ϊ�˷���������ԭ���ص������˵��ܵ�
�Ա���֪��������������
LONG);

        set("exits", ([
                "east"  : __DIR__"xdmidao4",
                "south" : __DIR__"xdmidao2",
        ]));

	setup();
        replace_program(ROOM);
}
