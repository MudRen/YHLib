inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
����Ѫ���ŵ�ɮ��Ϊ�˷���������ԭ���ص������˵��ܵ�
�Ա���֪��������������
LONG);

        set("exits", ([
                "north" : __DIR__"xdmidao3",
                "south" : __DIR__"xdmidao1",
        ]));

	setup();
        replace_program(ROOM);
}
