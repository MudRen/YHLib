inherit ROOM;

void create()
{
        set("short", "СϪ");
        set("long", @LONG
ɳ����Ȼ������ϡϡ��������ݣ��ٱ�һ�󣬵������
���ࡣת��֮�䣬��ǰ����һ��СϪ������Ϫ�ߣ�����һ��ˮ
���£�ֻ��һ��������ֱ͸�ķΡ���ˮ����֮�л�����΢΢��
������س���һ�����ѵ�Ȫˮ��Ϫˮ������С���������ײ��
��������������������ˣ��������֡�
LONG);
        set("outdoors", "gaochang");
        set("resource/water", 1);
        set("exits", ([ 
        	"north" : __DIR__"lake2",
        	"south" : __DIR__"lvzhou",
	]));
        setup();
}
