inherit ROOM;

void create()
{
        set("short", "��ɽ����");
        set("long", @LONG
�����������������ɽ��ΡȻ����������ʡ�����س��ϡ���ɽ���
�ӣ��������룬����ɽ��ߵʹ��䣬����һ�����������һ������������
ɽ�������������жȣ�������ɣ�ԶԶ��ȥ��״���޶���������Χ�����
���꣬�м�������������ɽ���򡺻���������ȡ����ɽ������������
�ٻ�ɽ���ʻ�ɽ�ֳ�̫���������С�������µ�һɽ��֮�ƣ�������һ��
С�壬���ɶ�����Ұ���ֱ�ɵ��￪�⸮��
LONG);
        set("exits", ([
            	"west" : "/d/village/eexit",
            	"east" : "/d/kaifeng/yezhulin",
            	"north" : __DIR__"yuquan",
            	"southeast" : __DIR__"shaluo",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "huashan" );

        setup();
        replace_program(ROOM);
}
