inherit SHOP;

void create()
{
	set("short", "�ٱ�ի");
	set("long", @LONG
�����ǳ�������С�������ĵ��á��ٱ�ի�����������ڸ�
ԣ��������۵Ļ���Ҳ�Ǳ��һ����������װ��÷ǳ����£�
����������ȴ����һ������Ѻܾ�û�˴����ˡ�
LONG);
        set("open_long", @LONG
�����ǳ�������С�������ĵ��á��ٱ�ի�����������ڸ�
ԣ��������۵Ļ���Ҳ�Ǳ��һ����������װ��÷ǳ����¡�
�����ϰ����˸�ʽ������������Ŀ�Ļ��
LONG);
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/changan/majiu",
        ]));
	set("no_steal", 1);
	set("objects", ([
                __DIR__"waiter" : 1,
        ]));
	set("no_clean_up", 0);
	set("shop_type", 0);

	setup();
}
