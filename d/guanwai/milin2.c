inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һƬï�ܵ����֣����ҵ���������б��ɽ���ϡ�ÿ��
�����������ı���ϸ���ߴ�ʮ���ɡ�����֦��Ҷ�ܣ��������
ȫ��ס����������Ե���Щ�谵����ľ֮�䳤�źܶ��ľ�Ӳ�
ʹ���ߺܼ��ѣ���˵�˲ξ���������Щ�Ӳ�֮�С�
LONG);
        set("exits", ([
                "westdown" : __DIR__"milin1",
                "southup"  : __DIR__"milin3",
        ]));
        set("objects", ([
                "/clone/quarry/laohu2" : 1,
        ]));
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);
}
