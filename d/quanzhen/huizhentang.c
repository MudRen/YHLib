inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǵ����Ե�һ��������Ҳ�ǽӴ���Ҫ���˵ĵط�����
����ֻ�ڷ���һ�����Ӻͼ������ӡ����ϰڷ���һ������ɽ
ʯ���辰��ǽ���Ϲ���һЩ�ֻ���
LONG);
        set("exits", ([
                "east" : __DIR__"cetang",
                "north" : __DIR__"wanwutang",
                "south" : __DIR__"datang1",
        ]));
        set("objects",([
              CLASS_D("quanzhen") + "/cui" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
