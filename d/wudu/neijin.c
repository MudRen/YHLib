inherit ROOM;

void create()
{
        set("short", "�ͷ�");
        set("long", @LONG
������һ��ͷ�����ǽ����һ��ͨ�̣������ۿ���������������
Ϣ�����߰���һ���������õ�ľ����һ���η��������������������
�ϺȲ衣
LONG);

        set("exits", ([
                "east" : __DIR__"xiaodian",
        ]));
        set("objects", ([
               CLASS_D("wudu") + "/daoshi" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
