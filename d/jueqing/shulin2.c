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
               "west"   : __DIR__"duanchang",
               "east"   : __DIR__"shulin3",           
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
