inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǹ߲��Թ������µĵ������ҡ�������С��ȴҲ��
���ȫ��ʯ��ʯ�Σ�ʯ��ʯ���������ڷŵļ�������Ҳ����
ʯ�Ƶġ������ƺ��ܾ���ǰ����������ס�������е�ʯ����ƽ
����һ�鱡����ʯ�壬����������Щʲô��
LONG);
    	set("exits", ([
        	"south" : __DIR__"mishi",
	]));
        "/clone/book/lbook5"->foo();
        setup();
        replace_program(ROOM);
}
