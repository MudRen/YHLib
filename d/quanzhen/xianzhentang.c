inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǵ����ԱߵĲ�����Ҳ�ǽӴ���Ҫ���˵ĵط�������
��ֻ�ڷ���һ�����Ӻͼ������ӡ����ϰڷ���һ���ɽ��ˮ
���辰��ǽ���Ϲ���һЩ�ֻ���������һ��ҩ���ҡ�
LONG);
        set("exits", ([
                "east" : __DIR__"piandian",
                "west" : __DIR__"yaojishi",
                "north" : __DIR__"datang1",
                "south" : __DIR__"rongwutang",
        ]));
        set("objects",([
              CLASS_D("quanzhen") + "/zhang" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
