inherit ROOM;

void create()
{
        set("short", "������Ժ");
        set("long", @LONG
���Ǹ���Ժ�ӣ��������߶������䳡��������������ϰ��
ǿ������ܳ����Һ��ģ��㿴����ʱ�п��Ŷ����ģ�����
ˮ�ĴҴҶ�����
LONG);
        set("no_fight", 1);
        set("exits", ([
                "south" : __DIR__"guofu_gate",
                "north" : __DIR__"guofu_dayuan2",
                "east" : __DIR__"guofu_lang2",
                "west" : __DIR__"guofu_lang1",
        ]));
        set("valid_startroom", 1);
        setup();
        "/clone/board/wuguan_b.c"->foo();
        replace_program(ROOM);
}
