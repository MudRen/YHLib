inherit ROOM;

void create()
{
        set("short", "é��");
        set("long", @LONG
����һ�������é�ݣ����Ʋ�ȫ��������ȥ���Կ����������
������������������������������ӻ�������һ���龰��
LONG );

        set("exits", ([
                "west" : "/d/kaifeng/shanlu2",
        ]));

        setup();
        replace_program(ROOM);
}
