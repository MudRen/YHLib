inherit SHOP;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������������Ǳ��֣���Ȼ��������ս�𲻶ϣ�����
�������ǲ��õþ������������й���һ���������֣�������
Ȼ�𾴡�������ȴ����һ��������ʱͣҵ�ˡ�
LONG);
        set("open_long", @LONG
�����������������Ǳ��֣���Ȼ��������ս�𲻶ϣ�����
�������ǲ��õþ������������й���һ���������֣�������
Ȼ�𾴡�������Ļ�����к��ſ��ˡ�
LONG);
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/xiangyang/majiu",
        ]));
	set("no_steal", 1);
	set("objects", ([
                __DIR__"waiter" : 1,
        ]));
	set("no_clean_up", 0);
	set("shop_type", 0);

	setup();
}
