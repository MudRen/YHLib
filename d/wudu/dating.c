inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǹ����Ĵ������ߴ��������һ�˶��ϱ���������������
ƽ�ս����ټ����������µĵط����������й�������ʥ--���ߣ�֩�룬
��򼣬Ы����ܵĻ��񡣼�λ������������������ ��
LONG);
        set("exits", ([
                "east" : __DIR__"huayuan1",
                "south" : __DIR__"jingshi",
                "west" : __DIR__"lianwu",
                "north" : __DIR__"shufang",
        ]));
        set("objects", ([
               CLASS_D("wudu") + "/qiyunao" : 1,
               CLASS_D("wudu") + "/panxiuda" : 1,
               CLASS_D("wudu") + "/cenqisi" : 1,
        ]));

        set("valid_startroom", 1);
        setup();
        "/clone/board/wudu_b"->foo();
}
