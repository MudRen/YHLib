// �ں�

inherit F_CLEAN_UP;
#include <ansi.h>

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object item;
        string msg;

        if (! arg) return notify_fail("��Ҫ��ʲô��Ʒ�ںϣ�\n");

        if (! objectp(item = present(arg, me)))
                return notify_fail("������û��������Ʒ��\n");

        if (! stringp(item->query("magic/type")) ||
            ! stringp(item->query("magic/tessera")))
                return notify_fail("�����Ʒ��û�г�Ϊʥ��޷���֮�ںϣ�\n");
     
        if (item->item_owner() != me->query("id"))
                return notify_fail("�㲻���������ˣ��޷���֮�ںϣ�\n");

        if (item->query("magic/blood") >= 5)
                return notify_fail("���Ѿ���֮��ȫ�ں��ˣ�\n");

        if (me->query("neili") < me->query("max_neili") * 9 / 10)
                return notify_fail("�����������������棬����óȻ��֮�ںϣ�\n");

        if (me->query("jingli") < me->query("max_jingli") * 9 / 10)
                return notify_fail("�����ھ������ã��޷���֮�ںϣ�\n");

        if (me->query("qi") < me->query("max_qi") * 9 / 10 ||
            me->query("max_qi") < 5000)
                return notify_fail("��������Ѫ���㣬�޷���֮�ںϣ�\n");

        message_sort(HIM "\n$N" HIM "��̾һ�����������Լ��İ���" + item->name() + HIM
                     "��ֻ��һ���׹�������$N" HIM "����Ѫ������" + item->name() + HIM
                     "�ϣ����Ǽ䣬���ʧɫ�������޹⣬��Ѫ�����ر�" + item->name() + HIM
                     "���ա������أ�$N" HIM "�������ں�Ϊһ�壡\n" NOR, me, item);

        msg = HIG "ͨ������ںϣ�����" + item->name() + HIG "��\n" NOR;
        msg += HIG "�ں϶����� 1 ��\n" NOR;
        msg += HIG "ħ�������� 10 ��\n" NOR;
        msg += HIR "��е��Լ�����Ѫ�������������½��ˡ�\n" NOR;
 
        item->add("magic/blood", 1);
        item->add("magic/power", 10);
        item->save();
        me->add("max_qi", -400);
        me->add("qi", -800);
        me->add("max_neili", -100);
        me->add("neili", -300);
        me->add("max_jingli", -100);
        me->add("jingli", -300);

        if (item->query("magic/blood") >= 5)
               msg += HIG "��е��Լ��Ѿ���" + item->name() + HIG "��ȫ�ں��ˣ�\n\n";
      
        else msg += "\n";
        
        tell_object(me, msg);


        return 1;

}

int help(object me)
{
write(@HELP
ָ���ʽ : syn <��Ʒ����>
 
���ָ������������Լ��ı����ںϡ�һ����������ں���Σ�ÿ��
�ںϺ��������ʮ�������ħ������һ���ں϶ȡ��ں϶ȴﵽ���Ժ�
����׷Ѱ��Ʒ������ÿ���ں���Ҫ��ʧ��������Ѫ���޺�������������
�������ޡ�����ʹ�ã�

HELP
);
    return 1;
}
