inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����ɽ��ˮ�̣���ɫ�������ģ�ֻ�����¼�����Ϣ������
͸�����գ�ż��ȴ����Լ����Ϫ������֮���ص���ɽ�ȡ� 
LONG);
        set("outdoors", "jueqing");
        set("exits", ([
               "west"   : __DIR__"shulin2",
               "east"   : __DIR__"shanlu6",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
