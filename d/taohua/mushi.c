inherit ROOM;

void create()
{
  
        set("short", "Ĺ��");
        set("long", @LONG
����һ�����Ĺ�ҡ�Ĺ�Ҷ�����һ���ر�����������
���⡣�������һ����ף���Χ��ѷ����������������档��
�Ź����������ǰ�����Ϸ��Ÿ����ӡ�Ĺ�Ҷ�������������
���Ļ��񡣻����ϵ��ٸ���Ц��Ȼ���ͲҰ׵���׼������͵�
����γ���һ�����Ļ��档
LONG);
        set("exits", ([
                "up" : __DIR__"mudao",
        ]));

        if (random(1000) > 998)
                set("objects", ([
                        "/clone/money/gold" : 10,
                        "/clone/fam/item/haoyue" : 1,
                        "/clone/fam/etc/lv5b" : 1,
                ]));
	else
        if (random(100) > 98)
                set("objects", ([
                        "/clone/money/gold" : 5,
                        "/clone/fam/etc/lv5a" : 1,
                ]));
	else
        if (random(100) > 97)
                set("objects", ([
                        "/clone/money/gold" : 5,
                        "/clone/fam/etc/lv5d" : 1,
                ]));
	else
        if (random(10) > 8)
                set("objects", ([
                        "/clone/money/gold" : 1,
                ]));

        setup();
}
